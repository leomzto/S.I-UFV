const simbolos = ["🍎", "🚀", "🐱", "⭐", "🎮", "⚽", "🍕", "💎"];
const tabuleiro = document.getElementById("tabuleiro");
const tentativasEl = document.getElementById("tentativas");
const paresEl = document.getElementById("pares");
const tempoEl = document.getElementById("tempo");
const mensagemEl = document.getElementById("mensagem");
const botaoReiniciar = document.getElementById("reiniciar");
const modalVitoria = document.getElementById("modal-vitoria");
const finalTentativas = document.getElementById("final-tentativas");
const finalTempo = document.getElementById("final-tempo");
const jogarNovamente = document.getElementById("jogar-novamente");

let primeiraCarta = null;
let segundaCarta = null;
let bloquearClique = false;
let tentativas = 0;
let paresEncontrados = 0;
let segundos = 0;
let cronometro = null;
let temporizadorCartas = null;

function embaralhar(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

function formatarTempo(totalSegundos) {
  const min = String(Math.floor(totalSegundos / 60)).padStart(2, "0");
  const seg = String(totalSegundos % 60).padStart(2, "0");
  return `${min}:${seg}`;
}

function iniciarCronometro() {
  pararCronometro();
  cronometro = setInterval(() => {
    segundos++;
    tempoEl.textContent = formatarTempo(segundos);
  }, 1000);
}

function pararCronometro() {
  if (cronometro !== null) {
    clearInterval(cronometro);
    cronometro = null;
  }
}

function criarCarta(simbolo) {
  const carta = document.createElement("button");
  carta.type = "button";
  carta.classList.add("carta");
  carta.dataset.simbolo = simbolo;
  carta.setAttribute("aria-label", "Carta escondida");
  carta.innerHTML = `
    <span class="card-inner">
      <span class="face front">?</span>
      <span class="face back">${simbolo}</span>
    </span>
  `;
  carta.addEventListener("click", () => virarCarta(carta));
  return carta;
}

function criarTabuleiro() {
  // TODO 1: Limpe o tabuleiro anterior.
  // TODO 2: Forme o vetor com dois de cada símbolo e embaralhe-o.
  // TODO 3: Crie as cartas e adicione-as ao tabuleiro.
}

function virarCarta(carta) {
  // TODO 1: Ignore cliques durante o bloqueio ou em cartas já viradas/encontradas.
  // TODO 2: Adicione a classe "virada" à carta selecionada.
  // TODO 3: Guarde a primeira carta em primeiraCarta.
  // TODO 4: Na segunda seleção, guarde segundaCarta e chame verificarPar().
}

function verificarPar() {
  // TODO 1: Bloqueie cliques enquanto compara o par.
  // TODO 2: Incremente tentativas e atualize tentativasEl.
  // TODO 3: Compare os dois dataset.simbolo.
  // TODO 4: Chame marcarComoEncontrada() ou desvirarCartas().
}

function marcarComoEncontrada() {
  // TODO 1: Adicione a classe "encontrada" às duas cartas e desabilite-as.
  // TODO 2: Incremente paresEncontrados e atualize paresEl.
  // TODO 3: Exiba mensagem de acerto e chame resetarJogada().
  // TODO 4: Se todos os 8 pares foram encontrados, pare o cronômetro,
  //         atualize os resultados finais e mostre modalVitoria.
}

function desvirarCartas() {
  mensagemEl.textContent = "As cartas são diferentes. Tente novamente.";
  // TODO 1: Utilize setTimeout(..., 2000).
  // TODO 2: Dentro da função agendada, retire a classe "virada" das cartas.
  // TODO 3: Limpe temporizadorCartas e chame resetarJogada().
  // Dica: armazene o identificador retornado pelo setTimeout em temporizadorCartas.
}

function resetarJogada() {
  primeiraCarta = null;
  segundaCarta = null;
  bloquearClique = false;
}

function reiniciarJogo() {
  // TODO 1: Pare o cronômetro e cancele temporizadorCartas, se existir.
  // TODO 2: Limpe a seleção e zere tentativas, paresEncontrados e segundos.
  // TODO 3: Atualize os contadores e a mensagem da página.
  // TODO 4: Esconda a janela de vitória.
  // TODO 5: Chame criarTabuleiro() e iniciarCronometro().
}

botaoReiniciar.addEventListener("click", reiniciarJogo);
jogarNovamente.addEventListener("click", reiniciarJogo);
reiniciarJogo();
