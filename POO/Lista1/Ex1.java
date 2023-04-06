import java.util.Scanner;

class Ex1 
{
public static void main(String[] args)
{
    double nota,total=0;
    int i=0;
    Scanner input = new Scanner(System.in);

    while(true)
    {
        nota = input.nextDouble();

        if(nota == -1)
            break;
        else
            i++;
        
        total+=nota;
    }
    input.close();
    total = total/i;

    System.out.println(
        "A media da turma foi " + total);
    
}   
    
}
