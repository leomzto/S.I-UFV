package ex05;

public class Main {
    static void main(String[] args) {
        ContaBancaria conta = null;

        try {
            conta = new ContaBancaria(100.0);
            System.out.println("Saldo inicial: R$ " + conta.getSaldo());

            double deposito = 50.0;
            System.out.println("Depositando R$ " + deposito + "...");

            conta.exibirSaldo();

            double saque = 300.0;
            System.out.println("Tentando sacar R$ " + saque + "...");
            conta.sacar(saque);

            System.out.println("Saque realizado com sucesso!"); // NAO SERA EXECUTADA POIS O SALDO É INSUFICIENTE
        } catch (ValorInvalidoException e) {
            System.err.println(e.getMessage());
        } catch (SaldoInsuficienteException e) {
            System.err.println(e.getMessage());
        } finally{
            if (conta != null){
                System.out.println("Saldo final: R$ " + conta.getSaldo());
            }
            System.out.println("Programa finalizado normalmente");
        }
    }
}
