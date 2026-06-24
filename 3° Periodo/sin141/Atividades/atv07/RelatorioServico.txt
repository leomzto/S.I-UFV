package com.ufv.locadora.servico;

import com.ufv.locadora.servico.VeiculoServico;
import com.ufv.locadora.servico.ClienteServico;
import com.ufv.locadora.servico.LocacaoServico;
import com.ufv.locadora.model.Locacao;
import com.ufv.locadora.model.StatusLocacao;

import java.util.List;

public class RelatorioServico {

    public void imprimirResumo(VeiculoServico vs, ClienteServico cs, LocacaoServico ls) {

        // Veiculo
        int totalVeiculos = vs.listarTodos().size();
        int veiculosDisponiveis = vs.listarDisponiveis().size();
        int veiculosEmLocacao = totalVeiculos - veiculosDisponiveis;

        // Cliente
        int totalClientes = cs.listarTodos().size();

        // Locação
        List<Locacao> todasLocacoes = ls.listarTodas();
        int totalLocacoes = todasLocacoes.size();
        int locacoesAtivas = (int) todasLocacoes.stream()
                .filter(l -> l.getStatus() == StatusLocacao.ATIVA)
                .count();
        int locacoesFinalizadas = (int) todasLocacoes.stream()
                .filter(l -> l.getStatus() == StatusLocacao.FINALIZADA)
                .count();
        int locacoesCanceladas = (int) todasLocacoes.stream()
                .filter(l -> l.getStatus() == StatusLocacao.CANCELADA)
                 .count();

        // Receita
        double receitaTotal = todasLocacoes.stream()
                .filter(l -> l.getStatus() == StatusLocacao.FINALIZADA)
                .mapToDouble(Locacao::getValorTotal)
                .sum();
        double receitaMedia = locacoesFinalizadas == 0 ? 0.0 : receitaTotal / locacoesFinalizadas;

        // Relatorio
        String relatorio = String.format(
                        "Total de veiculos: %d \n" +
                        "Disponiveis: %d | Em locação: %d \n" +
                        "Total de clientes: %d \n" +
                        "Total de locações: %d \n" +
                        "Ativas: %d | Finalizadas: %d | Canceladas: %d \n" +
                        "Receita total (finalizadas): R$ %.2f \n" +
                        "Receita media por locação: R$ %.2f",

                totalVeiculos, veiculosDisponiveis, veiculosEmLocacao,
                totalClientes, totalLocacoes, locacoesAtivas,
                locacoesFinalizadas, locacoesCanceladas, receitaTotal,
                receitaMedia
        );

        System.out.println(relatorio);
    }
}