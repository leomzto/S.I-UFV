package RevisaoP3.ex3dudu;

import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class Turma {
    private List<Aluno>alunos;
    private Map<String,Aluno>alunosPorMatricula;
    private Set<String>matriculasCadastradas;

    public Turma(){
        this.alunos = new ArrayList<>();
        this.alunosPorMatricula = new HashMap<>();
        this.matriculasCadastradas = new HashSet<>();
    }
    public void processarLinha(String linha){
        if(linha == null || linha.trim().isEmpty()){
            throw new IllegalArgumentException("linha vazia");
        }
        String[] dados = linha.split(";");
        if(dados.legth != 3) {
            throw new IllegalArgumentException("Formato incorreto");
        }
        String nome = dados[0].trim();
        String matricula = dados[1].trim();
        double nota = nota;

        try {
            nota=Double.parseDouble(dados[2].trim());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Nota invalida");
        }
        if(matriculasCadastradas.contains(matricula)){
            throw new IllegalArgumentException("Cadastre uma nova matricula");
        }
        Aluno novoAluno = new Aluno(nome, matricula, nota);

        alunos.add(novoAluno);
        alunosPorMatricula.put(matricula, novoAluno);
        matriculasCadastradas.add(matricula);
    }
    public String gerarRelatorio (){
        if(alunos.isEmpty()){
            return "nenhum aluno cadastrado";
        }

        double somaNotas = 0.0;
        Aluno alunoMaiorNota = alunos.getFirst();
        Aluno alunoMenorNota = alunos.getFirst();

        for(Aluno aluno : alunos){
            somaNotas += aluno.getNota();

            if(aluno.getNota() > alunoMaiorNota.getNota()){
                alunoMaiorNota = aluno;
            }
            if(aluno.getNota() < alunoMenorNota.getNota()){
                alunoMenorNota = aluno;
            }
        }
        double mediaNotas = somaNotas / alunos.size();

        StringBuilder sb =  new StringBuilder();
        sb.append("RELATORIO DA TURMA \n");
        sb.append("------------------ \n");

        sb.append("Quantidade de alunos cadastrados: \n").append(alunos.size()).append("\n");
        sb.append(String.format("Media geral: %.2f\n", mediaNotas));

        sb.append("Maior nota:\n");
        sb.append(alunoMaiorNota.getMatricula())
                .append(" - ").append(alunoMaiorNota.getNome())
                .append(" - ").append(alunoMaiorNota.getNota())
                .append("\n");
        sb.append("Menor nota: \n");
        sb.append(alunoMenorNota.getMatricula())
                .append(" - ").append(alunoMenorNota.getNome())
                .append(" - ").append(alunoMenorNota.getNota())
                .append("\n");

        sb.append("ALUNOS CADASTRADOS: \n");
        for (RevisaoP3.ex03.Aluno a : alunos) {
            sb.append(a.getMatricula())
                    .append(" - ").append(a.getNome())
                    .append(" - ").append(a.getNota())
                    .append("\n");
        }

        return sb.toString();

    }
}
