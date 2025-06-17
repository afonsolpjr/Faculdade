/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Laboratório: 11 */
/* Codigo: Criando um pool de threads em Java */

import java.util.LinkedList;
import static java.lang.Math.sqrt;

/**
 * Classe para implementação de uma fila de tarefas, com métodos para inserção e
 * finalização da fila.
 */
class FilaTarefas {
  private final int nThreads;
  private final MyPoolThreads[] threads;
  private final LinkedList<Runnable> queue;

  /**
   * Indica necessidade de finalização imediata das threads, caso true.
   */
  private boolean shutdown;

  /**
   * Constrói uma fila fila e um pool de threads para eventual execução de tarefas
   * na fila.
   * 
   * @param nThreads Número de threads a serem criadas.
   */
  public FilaTarefas(int nThreads) {
    this.shutdown = false;
    this.nThreads = nThreads;
    queue = new LinkedList<Runnable>();
    threads = new MyPoolThreads[nThreads];
    for (int i = 0; i < nThreads; i++) {
      threads[i] = new MyPoolThreads();
      threads[i].start();
    }
  }

  /**
   * Insere uma tarefa,na forma de um objeto runnable, na fila.
   * 
   * @param r Objeto runnable, representando um trabalho a ser feito.
   */
  public void execute(Runnable r) {
    synchronized (queue) {
      if (this.shutdown)
        return;
      queue.addLast(r);
      queue.notify();
    }
  }

  /**
   * Finaliza a execução das threads.
   */
  public void shutdown() {
    synchronized (queue) {
      this.shutdown = true;
      queue.notifyAll();
    }
    for (int i = 0; i < nThreads; i++) {
      try {
        threads[i].join();
      } catch (InterruptedException e) {
        return;
      }
    }
  }

  /**
   * Classe que representa as threads, e o trabalho que elas devem realizar, no
   * método run.
   */
  private class MyPoolThreads extends Thread {
    public void run() {
      Runnable r;
      while (true) {
        synchronized (queue) {
          while (queue.isEmpty() && (!shutdown)) {
            try {
              queue.wait();
            } catch (InterruptedException ignored) {
            }
          }
          if (queue.isEmpty())
            return;
          r = (Runnable) queue.removeFirst();
        }
        try {
          r.run();
        } catch (RuntimeException e) {
        }
      }
    }
  }
}

// --PASSO 1: cria uma classe que implementa a interface Runnable
class Hello implements Runnable {
  String msg;

  public Hello(String m) {
    msg = m;
  }

  // --metodo executado pela thread
  public void run() {
    System.out.println(msg);
  }
}

class Primo implements Runnable {
  private int n;

  public Primo(int n) {
    this.n = n;
  }

  public void run() {
    if (ehPrimo())
      System.out.println(n + " é primo");
    else
      System.out.println(n + " não é primo");
  }

  private boolean ehPrimo() {
    int i;
    if (n <= 1)
      return true;
    if (n == 2)
      return true;
    if (n % 2 == 0)
      return false;
    for (i = 3; i < sqrt(n) + 1; i += 2) {
      if (n % i == 0)
        return false;
    }
    return true;
  }
}

/**
 * Classe que contém o método main.
 */
class MyPool {
  private static final int NTHREADS = 10;

  public static void main(String[] args) {
    // --PASSO 2: cria o pool de threads
    FilaTarefas pool = new FilaTarefas(NTHREADS);

    // --PASSO 3: dispara a execução dos objetos runnable usando o pool de threads
    for (int i = 0; i < 25; i++) {
      // final String m = "Hello da tarefa " + i;
      // Runnable hello = new Hello(m);
      // pool.execute(hello);
      Runnable primo = new Primo(i);
      pool.execute(primo);
    }

    // --PASSO 4: esperar pelo termino das threads
    pool.shutdown();
    System.out.println("Terminou");
  }
}
