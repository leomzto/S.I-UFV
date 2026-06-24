package ex01;

import java.util.Map;
import java.util.List;
import java.util.HashMap;

public class Biblioteca {
    private Repositorio<Livro> repositorio;
    private Map<String, Livro> livrosPorIsbn;

    public Biblioteca(){
        this.livrosPorIsbn = new HashMap<>();
        this.repositorio = new Repositorio<>();
    }

    public void adicionar(Livro livro){
        if(livro == null){
            throw new IllegalArgumentException("o livro deve ser valido");
        }
        if(this.livrosPorIsbn.containsKey(livro.getIsbn())){
            throw new IllegalArgumentException("Livro ja cadastrado.");
        }

        repositorio.adicionar(livro);
        this.livrosPorIsbn.put(livro.getIsbn(), livro);
    }

    public Livro buscarPorISBN(String isbn){
        Livro l =  this.livrosPorIsbn.get(isbn);
        if(l == null){
            System.out.println("livro nao encontrado");
        }
        return l;
    }
    public List<Livro> listarTodos(){
        return repositorio.listar();
    }
}
