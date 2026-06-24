package ex03;

public class Aluno {
    private String nome;
    private String matricula;
    private double nota;

    public Aluno(String nome, String matricula, double nota) {
        if (nome == null || nome.trim().isEmpty()) {
            throw new IllegalArgumentException("Nome invalido");
        }
        if (matricula == null || matricula.trim().isEmpty()) {
            throw new IllegalArgumentException("Matricula invalida");
        }
        if (nota < 0.0 || nota > 10.0) {
            throw new IllegalArgumentException("Nota Invalida");
        }

        this.nome = nome.trim();
        this.matricula = matricula.trim();
        this.nota = nota;
    }

    public String getNome() { return nome; }
    public String getMatricula() { return matricula; }
    public double getNota() { return nota; }
}
