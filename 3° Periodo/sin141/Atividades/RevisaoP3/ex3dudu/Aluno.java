package RevisaoP3.ex3dudu;

public class Aluno {
    private String nome;
    private String matricula;
    private double nota;

    public Aluno(String nome, String matricula, double nota) {
        if(nome == null || nome.trim().isEmpty()){
            throw new IllegalArgumentException("nome invalido");
        }
        if(matricula == null || matricula.trim().isEmpty()){
            throw new IllegalArgumentException("matricula invalida");
        }
        if(nota < 0.0 || nota > 10.0){
            throw new IllegalArgumentException("nota invalida");
        }
        this.nome = nome.trim();
        this.matricula = matricula.trim();
        this.nota = nota;
    }
    public String getNome() {
        return nome;
    }
    public String getMatricula() {
        return matricula;
    }
    public double getNota() {
        return nota;
    }
}
