package lista3.exec_5;

public class Conta {

    private double saldo;





    public Conta()
    {
        this.saldo = 0;
    }


    public double pegaSaldo()
    {
        return this.saldo;
    } 

    public void deposita(double n)
    {
        this.saldo+=n;
    }

    public boolean saca(double n)
    {
        if(n>this.saldo)
            return false;
        else
        {
            this.saldo -= n;
            return true;
        }
    }

}
