
window.onload = function(){

	var body = document.getElementById("b");
	body.onload = changeColor();

	var calcButton = document.getElementById("calc");
	calcButton.onclick = calc;

	var stopButton =  document.getElementById("stop");
	stopButton.onclick = stopTextColor;

	var guessButton = document.getElementById("guess");
	guessButton.onclick = guess;

	var replayButton = document.getElementById("replay");
	replayButton.onclick = replay;

	var changeButton = document.getElementById("change");
	changeButton.onclick = changeImage;

	var createButton = document.getElementById("ctCreate1");
	createButton.onclick = createColorTable;

	var removeButton = document.getElementById("ctCreate2");
	removeButton.onclick = removeColorTable;

	var moveButton = document.getElementById("move");
	moveButton.onclick = myMove;

	var guessButton2 = document.getElementById("guessbutton");
	guessButton2.onclick = guessLetter;

	var newButton = document.getElementById("new");
	newButton.onclick = newGame;
};


function calc() {
	var x = document.getElementById('x').value;
	var y = document.getElementById('y').value;
	var sum;
	sum = parseInt(x) + parseInt(y);
	document.getElementById("sum").value = sum;
}


var computerNumber = 53;
var nGuesses = 0;

function guess() {

	var user = document.getElementById('user').value;

	if(user > computerNumber){
		document.getElementById("result").value = "높습니다.";
		nGuesses++;
		document.getElementById("guesses").value = parseInt(nGuesses);
	}
	else if(user < computerNumber){
		document.getElementById("result").value = "낮습니다.";
		nGuesses++;
		document.getElementById("guesses").value = parseInt(nGuesses);
	}	
	else {
		document.getElementById("result").value = "정답입니다.";
		nGuesses++;
		document.getElementById("guesses").value = parseInt(nGuesses);
	}	
}

function replay() {

	nGuesses = 0;

	computerNumber = Math.floor(Math.random() * 100 + 1);
	document.getElementById("user").value = "";
	document.getElementById("guesses").value = nGuesses;
	document.getElementById("result").value = "";

}

function setCTime() {
	var now = new Date();
	var monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" ];
	var s = monthNames[now.getMonth()] + " " + (now.getMonth() + 1) + ". " + now.getDate() + " " + now.getHours()  + ":" + now.getMinutes() + ":" + now.getSeconds();
	document.getElementById('ctime').innerHTML = s;
	setTimeout('setCTime()',1000);
}

function changeImage(){
	var bimg = document.getElementById("image");
	var sarray = bimg.src.split('/');
	var str = sarray[sarray.length-1];
	if(str == "img1.png")
		bimg.src = "img2.png";
	else
		bimg.src = "img1.png"; 
}

var colorNames = ["maroon","red","orange","yellow","olive","purple","fuchsia","white",
"lime","green","navy","blue","aqua","teal","black","silver","gray"];

function createColorTable(){
	var colordiv = document.getElementById("colorTable");
	for(var i=0; i<colorNames.length;i++){
		var ndiv = document.createElement("div");
		ndiv.setAttribute("class","ctbox");
		ndiv.innerHTML = colorNames[i];
		ndiv.style.display = "inline-block";
		ndiv.style.width = "60px";
		ndiv.style.padding="10px";
		ndiv.style.backgroundColor = colorNames[i];
		colordiv.appendChild(ndiv);
	}
}
function removeColorTable(){
	var parent = document.getElementById("colorTable");
	var child = parent.getElementsByTagName("div");
	var child = parent.getElementsByClassName("ctbox");
	var child = parent.childNodes;
	while(child[0]){
		parent.removeChild(child[0]);
	}
}

var change;
function changeColor(){

	change = setInterval(colorText,1000);

	function colorText(){
		var e = document.getElementById("target");
		if(e.style.color == "red"){
			e.style.color = "blue";
		}
		else{
			e.style.color = "red";
		}

		if(e.style.backgroundColor == "green"){
			e.style.backgroundColor = "yellow";
		}
		else{
			e.style.backgroundColor = "green";
		}
	}
}
function stopTextColor(){
	clearInterval(change);
}


function myMove(){

	var e = document.getElementById("animate");
	var pos=0;
	var id = setInterval(frame,5);
	function frame(){
		if(pos == 350){
			clearInterval(id);
		}
		else{
			pos++;
			e.style.top = pos+'px';
			e.style.left = pos+'px';
		}
	}

}

// constants
var POSSIBLE_WORDS = ["obdurate","verisimilitude","defenestrate", "obsequious", "dissonant","toady","idempotent"];
var MAX_GUESSES = 6;

// global variables
var guesses = "";
var guessCount = MAX_GUESSES;
var word;

function newGame(){
	var randomIndex = parseInt(Math.random()*POSSIBLE_WORDS.length);
	word = POSSIBLE_WORDS[randomIndex];
	guessCount = MAX_GUESSES;
	guesses = "";
	var guessButton = document.getElementById("guessbutton");
	guessButton.disabled = false;
	updatePage();
}

function guessLetter(){

	var input = document.getElementById("hguess");
	var clue = document.getElementById("clue");
	var letter = input.value
	if(guessCount==0 || clue.innerHTML.indexOf("_") < 0 || guesses.indexOf(letter) >= 0){
		return;
	}
	guesses += letter;
	if(word.indexOf(letter)<0){
		guessCount--;
	}
	updatePage();
}

function updatePage(){

	var clueString = "";
	for(var i=0;i<word.length;i++){
		var letter = word.charAt(i);
		if(guesses.indexOf(letter)>=0){
			clueString += letter + " ";
		}else{
			clueString += "_ ";
		}
	}
	var clue = document.getElementById("clue");
	clue.innerHTML = clueString;

	var guessArea = document.getElementById("guessstr");
	if(guessCount==0){
		guessArea.innerHTML = "You lose.";
	}else if (clueString.indexOf("_")<0){
		guessArea.innerHTML = "You win.";
	}else{
		guessArea.innerHTML = "Guesses: " + guesses;
	}

	var image = document.getElementById("hangmanpic");
	image.src = "hangman"+ guessCount + ".gif";
}


