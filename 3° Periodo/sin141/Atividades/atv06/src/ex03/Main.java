package ex03;

public class Main {
    static void main(String[] args) {
        ContaBancaria conta = new ContaBancaria();

        try {
            conta.setSaldo(100);
            System.out.println("Saldo inicial: R$ " + conta.getSaldo());

            double saque = 150.0;
            System.out.println("Tentando sacar R$ " + saque + "...");
            conta.sacar(saque);

            System.out.println("Saldo disponivel: R$ " + conta.getSaldo());
        } catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        } catch (SaldoInsuficienteException e) {
            System.err.println(e.getMessage());
        }

        System.out.println("Programa finalizado normalmente");

    }
}
