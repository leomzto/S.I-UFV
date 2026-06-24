package RevisaoP2.ex01;

public class Main {
    public static void main(String[] args) {
        Funcionario[] funcionarios = {
                new Gerente("Ana", 5000.0, 1500.0),
                new Desenvolvedor("Carlos", 3000.0, 10),
                new Estagiario("Marina", 1200.0, 300.0)
        };
        for (Funcionario f : funcionarios) {
            f.exibirDados();
        }
    }
}
