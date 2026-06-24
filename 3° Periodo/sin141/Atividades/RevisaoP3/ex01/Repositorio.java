package RevisaoP3.ex01;
import java.util.ArrayList;
import java.util.List;
public class Repositorio<T> {
    private List<T> itens;

    public Repositorio(){
        this.itens = new ArrayList<>();
    }

    public void adicionar(T objeto) {
        if(objeto == null){
            throw new IllegalArgumentException("nao eh possivel adicionar um elemento nulo. ");
        }
        this.itens.add(objeto);
    }

    public List<T> listar(){
        return new ArrayList<>(this.itens);
    }
}
