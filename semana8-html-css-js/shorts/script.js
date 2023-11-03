// var, let ...
// Array
// POO -> objetos (análogo às 'structs' de C)
// objetos em JS -> dicionários no Python

// em JS tudo é um caso especial de objeto (e praticamente tudo possui métodos e atributos; array, inteiros, strings ...)

// Loops (redux) -> iterando nos pares chave-valor de um objeto (ou nos elementos de um array)

let x = {t : 10, y : 12, z : 34, b : 44};
for (let i in x)
{
    // exibe chave e valor
    // console.log(`${i}, ${x[i]}`)
}

let y = [0, 3, 5, 33];
// console.log("====")
for (let j in y)
{
    // somente j exibiria o índice, assim exibe o elemento
    // console.log(y[j])
}

// console.log("====")
for (let j of y)
{
    // 'of' itera somente nos elementos
    // console.log(j)
}

/*
Python
    x = [1,2,3,4]
    for i in x:
        print i
*/

// Functions (redux)
// 'map' aplica uma função para cada elemento da coleção

let num = [1, 2, 6, 4, 7, 8, 9];

// função anônima
let num2 = num.map(function(n)
{
    return n * 10
});

console.log(num)
console.log(num2)

// Eventos -> resposta do JS à eventos ocorridos no HTML
// Eventos podem ser usados no elemento HTML mas isso não costuma ser boa prática, é bom isolar todos os eventos no JavaScript

// DOM
// 'document' é um objeto! / "document object model"
// é como se toda a página html fosse carregada no objeto 'document' em estrutura de árvore, cada nó sendo também um objeto que herda de 'document'
// sendo objeto, posso usar métodos e atributos para manipular os elementos do documento

// DOM Properties / DOM Methods

// manipular o DOM é algo bem verboso, portanto há frameworks que facilitam isso, tipo o 'JQuery'