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
  // 1. Limpa o tabuleiro anterior
  tabuleiro.innerHTML = "";

  // 2. Dois de cada símbolo, embaralhados
  const baralho = embaralhar([...simbolos, ...simbolos]);

  // 3. Cria as cartas e adiciona ao tabuleiro
  baralho.forEach((simbolo) => {
    tabuleiro.appendChild(criarCarta(simbolo));
  });
}

function virarCarta(carta) {
  // 1. Ignora cliques durante o bloqueio ou em cartas já viradas/encontradas
  if (
    bloquearClique ||
    carta.classList.contains("virada") ||
    carta.classList.contains("encontrada")
  ) {
    return;
  }

  // 2. Vira a carta
  carta.classList.add("virada");
  carta.setAttribute("aria-label", `Carta ${carta.dataset.simbolo}`);

  // 3. Primeira carta
  if (primeiraCarta === null) {
    primeiraCarta = carta;
    return;
  }

  // 4. Segunda carta: verifica o par
  segundaCarta = carta;
  verificarPar();
}

function verificarPar() {
  // 1. Bloqueia cliques durante a comparação
  bloquearClique = true;

  // 2. Conta a tentativa
  tentativas++;
  tentativasEl.textContent = tentativas;

  // 3. Compara os símbolos
  const iguais = primeiraCarta.dataset.simbolo === segundaCarta.dataset.simbolo;

  // 4. Acerto ou erro
  if (iguais) {
    marcarComoEncontrada();
  } else {
    desvirarCartas();
  }
}

function marcarComoEncontrada() {
  // 1. Marca e desabilita as duas cartas
  [primeiraCarta, segundaCarta].forEach((c) => {
    c.classList.add("encontrada");
    c.disabled = true;
  });

  // 2. Atualiza o contador de pares
  paresEncontrados++;
  paresEl.textContent = paresEncontrados;

  // 3. Mensagem de acerto e reset da jogada
  mensagemEl.textContent = "Muito bem! Você encontrou um par.";
  resetarJogada();

  // 4. Vitória
  if (paresEncontrados === simbolos.length) {
    pararCronometro();
    finalTentativas.textContent = tentativas;
    finalTempo.textContent = formatarTempo(segundos);
    mensagemEl.textContent = "Parabéns! Você encontrou todos os pares.";
    modalVitoria.classList.remove("oculto");
    modalVitoria.hidden = false;
  }
}

function desvirarCartas() {
  mensagemEl.textContent = "As cartas são diferentes. Tente novamente.";

  // 1. Agenda o desvirar por 2 segundos
  temporizadorCartas = setTimeout(() => {
    // 2. Remove a classe "virada" das duas cartas
    primeiraCarta.classList.remove("virada");
    segundaCarta.classList.remove("virada");
    primeiraCarta.setAttribute("aria-label", "Carta escondida");
    segundaCarta.setAttribute("aria-label", "Carta escondida");

    // 3. Limpa o temporizador e libera a jogada
    temporizadorCartas = null;
    resetarJogada();
  }, 2000);
}

function resetarJogada() {
  primeiraCarta = null;
  segundaCarta = null;
  bloquearClique = false;
}

function reiniciarJogo() {
  // 1. Para o cronômetro e cancela o temporizador pendente
  pararCronometro();
  if (temporizadorCartas !== null) {
    clearTimeout(temporizadorCartas);
    temporizadorCartas = null;
  }

  // 2. Limpa a seleção e zera os contadores
  resetarJogada();
  tentativas = 0;
  paresEncontrados = 0;
  segundos = 0;

  // 3. Atualiza a interface
  tentativasEl.textContent = tentativas;
  paresEl.textContent = paresEncontrados;
  tempoEl.textContent = formatarTempo(segundos);
  mensagemEl.textContent = "Encontre todos os pares!";

  // 4. Esconde a janela de vitória
  modalVitoria.classList.add("oculto");
  modalVitoria.hidden = true;

  // 5. Novo tabuleiro e cronômetro
  criarTabuleiro();
  iniciarCronometro();
}

botaoReiniciar.addEventListener("click", reiniciarJogo);
jogarNovamente.addEventListener("click", reiniciarJogo);
reiniciarJogo();