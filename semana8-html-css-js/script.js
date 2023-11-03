// selecionando o elemento 'body'
let body = document.querySelector('body');

// mudando a cor do background a partir de cliques nos botões
document.querySelector('#red').addEventListener('click', function() {
    body.style.backgroundColor = 'red';
});
document.querySelector('#green').addEventListener('click', function() {
    body.style.backgroundColor = 'green';
});
document.querySelector('#blue').addEventListener('click', function() {
    body.style.backgroundColor = 'blue';
});
document.querySelector('#texto').addEventListener('click', function() {
    body.style.backgroundColor = 'white';
});

// função que faz a janela piscar
function blink()
{
    if (body.style.visibility == 'hidden')
    {
        body.style.visibility = 'visible';
    }
    else
    {
        body.style.visibility = 'hidden';
    }
}

// piscar a cada 500 milisegundos
// window.setInterval(blink, 500);

// ???
let input = document.querySelector('input');
input.addEventListener('keyup', function(event){
    let html = '';
    if (input.value)
    {
        for (word of WORDS)
        {
            if (word.startsWith(input.value))
            {
                html += '<li>${word}</li>';
            }
        }
    }
    document.querySelector('ul').innerHTML = html;
});

// localização geográfica
/*
navigator.geolocation.getCurrentPosition(function(position){
    document.write(position.coords.latitude + ", " + position.coords.longitude);
});
*/