package RevisaoP3.ex03;

import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;

public class Turma {
    private List<Aluno> alunos;
    private Map<String,Aluno> alunosPorMatricula;
    private Set<String> matriculasCadastradas;

    public Turma() {
        this.alunos = new ArrayList<>();
        this.alunosPorMatricula = new HashMap<>();
        this.matriculasCadastradas = new HashSet<>();
    }

    public void processarLinha(String linha) {
        if (linha == null || linha.trim().isEmpty()) {
            throw new IllegalArgumentException("Linha vazia");
        }

        String[] dados = linha.split(";");
        if (dados.length != 3) {
            throw new IllegalArgumentException("Formato incorreto, deve ser: Nome;Matricula;Nota");
        }

        String nome = dados[0].trim();
        String matricula = dados[1].trim();
        double nota;

        try {
            nota = Double.parseDouble(dados[2].trim());
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Nota invalida");
        }
        if (matriculasCadastradas.contains(matricula)) {
            throw new IllegalArgumentException("Aluno ja matriculado na turma");
        }

        Aluno novoAluno = new Aluno(nome, matricula, nota);

        alunos.add(novoAluno);
        matriculasCadastradas.add(matricula);
        alunosPorMatricula.put(nome, novoAluno);
    }

    public String gerarRelatorio() {
        if (alunos.isEmpty()) {
            return "Nenhum aluno cadastrado";
        }

        double somaNotas = 0;
        Aluno alunoMaiorNota = alunos.getFirst();
        Aluno alunoMenorNota = alunos.getFirst();

        for (Aluno a : alunos) {
            somaNotas += a.getNota();

            if (a.getNota() > alunoMaiorNota.getNota()) {
                alunoMaiorNota = a;
            }
            if (a.getNota() < alunoMenorNota.getNota()) {
                alunoMenorNota = a;
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
        for (Aluno a : alunos) {
            sb.append(a.getMatricula())
                    .append(" - ").append(a.getNome())
                    .append(" - ").append(a.getNota())
                    .append("\n");
        }

        return sb.toString();
    }
}
