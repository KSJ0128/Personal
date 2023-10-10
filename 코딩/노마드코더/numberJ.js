
const inputRandom = document.querySelector(".random");
const inputNumber = document.querySelector(".number");
const button = document.querySelector("button");
const result = document.querySelector(".result");

function handleSubmit(event){
    event.preventDefault();
    const randomNumber = Math.ceil(Math.random()*inputRandom);
    const userNumber = inputNumber.value;
    result.innerHTML = `You chose: ${userNumber}, the machine chose: ${randomNumber}.</br>
    {${userNumber===randomNumber ? "You won!" : "You lose"}`;
}

button.addEventListener("submit",handleSubmit);