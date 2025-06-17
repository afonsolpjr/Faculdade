/* Disciplina: Programacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Laboratório: 11 */
/* Codigo: Exemplo de uso de futures */
/* -------------------------------------------------------------------*/

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import static java.lang.Math.sqrt;
import java.util.ArrayList;
import java.util.List;

//classe runnable
class MyCallable implements Callable<Boolean> {
  // construtor
  private int n;

  MyCallable(int n) {
    this.n = n;
  }

  // método para execução
  public Boolean call() {
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

// classe do método main
public class FutureHello {
  private static final int N = 999999;
  private static final int NTHREADS = 10;

  public static void main(String[] args) {

    /**
     * Cria um pool com NTHREADS.
     */
    ExecutorService executor = Executors.newFixedThreadPool(NTHREADS);

    /**
     * Lista para referências de chamadas assíncronas.
     * O i-ésimo elemento será true se i for primo.
     */
    List<Future<Boolean>> list = new ArrayList<Future<Boolean>>(N);

    System.out.println("N = " + N);

    for (int i = 1; i <= N; i++) {
      Callable<Boolean> worker = new MyCallable(i);
      Future<Boolean> submit = executor.submit(worker);
      list.add(submit);
    }

    // recupera os resultados e faz o somatório final
    long sum = 0;
    for (int i = 0; i < N; i++) {
      try {
        // Primeiro get é para acessar i-ésimo elemento na lista. Segundo é para o valor
        // do Future
        if (list.get(i).get()) {
          System.out.println((i + 1) + " é primo");
          sum++;
        }
      } catch (InterruptedException e) {
        e.printStackTrace();
      } catch (ExecutionException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Primos encontrados: " + sum);
    executor.shutdown();
  }
}
