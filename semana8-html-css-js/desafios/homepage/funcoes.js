// Para cada página carregada existe um objeto da classe (interface) Document, que serve como um ponto de entrada para a interface da página, o DOM. Element é a classe de que todo objeto da classe Document(DOM) herda.


let cs50p = document.querySelector("#cs50p");
let py4e = document.querySelector("#py4e");

cs50p.addEventListener('click', function(){
    document.querySelector("#projeto1").innerHTML = "Projeto do CS50: POO, Exceções, Regex, Testes ...";

    
    // teste de foco em elemento específico
    // 'Element.scrollIntoView' é método da classe 'Element', e dá foco no elemento no qual a ação está sendo executada. Pode receber um objeto(tipo um dicionário) para definir comportamentos.
    document.querySelector("#foco").scrollIntoView({behavior:"smooth", block:"center"});
});

// 'click' é o tipo do evento
py4e.addEventListener('click', function(){
    document.querySelector("#projeto2").innerHTML = "O Dr. Chuck pegou pesado no final ...";
});
