
function getInt(){
    return Math.floor(Math.random() * 4);
}

function playSequence(sequence){
    interval=0;
    for(var i = 0;i<sequence.length;i++)
    {
        setTimeout(playSquareSound,interval,colors[sequence[i]],false);
        interval+=999;
    }
}

function playSquareSound(id,from_player)
{
    // console.log("id:"+id);
    from_player? interval = 200: interval = 400;
    // colors.includes(this.id)? (id = this.id) && (interval=200): id;

    button = document.getElementById(id);
    
    button.classList.add("pressed");
    setTimeout(function(){button.classList.remove("pressed")},interval);

    sound_str = "./sounds/"+id+".mp3";
    sound = new Audio(sound_str);
    sound.play();
}

function gameOver(){
    disableUserInput();

    sound = new Audio("./sounds/wrong.mp3");
    sound.play();
    console.log("gameover");
    fundo = document.querySelector("body");
    fundo.style.backgroundColor="red";
    setTimeout(function(){fundo.style.backgroundColor="#011F3F"},1000);
    lvl_indicator.innerText="Game Over! Press a Key to Start!";
    waitForStart();
}

function waitForStart(){
    document.addEventListener("keydown",startGame);
}


function startGame()
{
    document.removeEventListener("keydown",startGame);
    console.log("game started");
    lvl = 1;
    sequence = [];
    startLevel();
}

function startLevel(){
    disableUserInput();
    lvl_indicator.innerText = "Level: "+lvl;
    sequence.push(getInt());
    // console.log("sequence:"+sequence);
    setTimeout(playSequence,1300,sequence);
    guesses_number = 0;
    setTimeout(waitForPlayer,1000);
}


function playerGuessed(element)
{
    console.log(element.id,this.id);
    if(this.id)
    {
        // if clicked
        guess = this.id;
    }
    else
    {
        // if pressed key
        guess = element.id;
    }

    console.log("guess:"+guess+"\n"+
        "guesses_number:"+guesses_number+"\n"+
        "correct:"+colors[sequence[guesses_number]]+'\n'+
        "resultado:"+(guess===colors[sequence[guesses_number]]));
    playSquareSound(guess,true);

    if(guess===colors[sequence[guesses_number]])
    {
        if (++guesses_number===lvl) //if guessed and need to advance level
        {
        
            lvl++;
            setTimeout(startLevel,500);
        }
    }
    else
        gameOver();
}
function keyPressed(event){
    
    if(!(['q','w','a','s'].includes(event.key)))
    return;

    switch(event.key){
    case 'q':
        playerGuessed(document.getElementById("green"));
        break;
    case 'w':
        playerGuessed(document.getElementById("red"));
        break;
    case 'a':
        playerGuessed(document.getElementById("yellow"));
        break;
    case 's':
        playerGuessed(document.getElementById("blue"));
        break;
}

}



/* These functions were supposed to enable/disable user input at the right times. But since settimeout is asynchronous, went wrong. And i did not came up with an alternative to achieve this (yet?). */
function waitForPlayer(){
    for(var i=0;i<4;i++)
    {
        document.getElementById(colors[i]).addEventListener("click",playerGuessed);
    }
    document.addEventListener("keydown",keyPressed)
    console.log("guesses_number:"+guesses_number+"\n"+
        "correct:"+colors[sequence[guesses_number]]+'\n');
}

function disableUserInput()
{
    document.removeEventListener("keydown",keyPressed);
    for(var i=0;i<4;i++)
    {
        document.getElementById(colors[i]).removeEventListener("click",playerGuessed);
    };
}


var colors = ["green","red","yellow","blue"];
var guesses_number;
var lvl;
var sequence;
var lvl_indicator = document.getElementById("level-title");

waitForStart();

