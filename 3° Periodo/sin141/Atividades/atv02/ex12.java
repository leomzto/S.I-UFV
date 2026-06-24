package atv02;

class HistoricoTransferencia {
    String cpfOrigem;
    String cpfDestino;
    double valor;

    public HistoricoTransferencia(String cpfOrigem, String cpfDestino, double valor) {
        this.cpfOrigem = cpfOrigem;
        this.cpfDestino = cpfDestino;
        this.valor = valor;
    }

    void exibirTransferencia() {
        System.out.println("Origem: " + cpfOrigem);
        System.out.println("Destino: " + cpfDestino);
        System.out.println("Valor: R$ " + valor);
    }
}