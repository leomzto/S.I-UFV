package ex02;

public class Funcionario {
    private String nome;
    private String cpf;
    private String email;
    private String departamento;

    public Funcionario(String nome, String cpf, String email, String departamento) {
        if (nome == null || nome.trim().isEmpty()) {
            throw new IllegalArgumentException("nome nao pode ser vazio ou nulo");
        }
        if (cpf == null || cpf.trim().isEmpty()) {
            throw new IllegalArgumentException("cpf nao pode ser vazio ou nulo");
        }
        if (email == null || email.trim().isEmpty() || !email.contains("@")) {
            throw new IllegalArgumentException("email invalido");
        }
        if (departamento == null || departamento.trim().isEmpty()) {
            throw new IllegalArgumentException("departamento nao pode ser vazio ou nulo");
        }

        String cpfLimpo = cpf.replace(".", "")
                .replace("-", "")
                .trim();
        if (cpfLimpo.length() != 11) {
            throw new IllegalArgumentException("cpf tem que ter 11 digitos");
        }

        this.nome = nome.trim();
        this.cpf = cpfLimpo;
        this.email = email.toLowerCase().trim();
        this.departamento = departamento.toUpperCase().trim();
    }

    public String gerarLogin() {
        String[] nomeDividido = this.nome.split(" ");
        String primeiroNome = nomeDividido[0].toLowerCase();
        String login = primeiroNome + "." + this.departamento;
        return login;
    }

    public String gerarRelatorio() {
       StringBuilder sb =  new StringBuilder();
       sb.append("Relatorio \n");
       sb.append("Nome: ").append(this.nome).append("\n");
       sb.append("CPF: ").append(this.cpf).append("\n");
       sb.append("Email: ").append(this.email).append("\n");
       sb.append("Departamento: ").append(this.departamento).append("\n");
       sb.append("Login gerado: ").append(gerarLogin()).append("\n");
       return sb.toString();
    }

    public String getNome() { return this.nome; }
    public String getCpf() { return this.cpf; }
    public String getEmail() { return this.email; }
    public String getDepartamento() { return this.departamento; }
}
