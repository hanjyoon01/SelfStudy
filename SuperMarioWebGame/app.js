$(document).ready(function () {

    var canvas = document.getElementById("my_canvas");
    var ctx = canvas.getContext("2d");
    var x = canvas.width / 2;
    var y = canvas.height - 60;
    var dx = 4;
    var dy = -4;
    var ballRadius = 10; //공 반지름
    var paddleHeight = 54; //패들 높이
    var paddleWidth = 100; //패들 너비
    var brickRowCount; // 벽돌 가로줄 개수
    var brickColumnCount = 7; //벽돌 세로줄 개수
    var brickWidth = 120; //벽돌 너비
    var brickHeight = 60; //벽돌 높이
    var brickPadding = 0;
    var brickOffsetTop = 0;
    var brickOffsetLeft = 0;
    var brickOffsetBottom = 180;
    var lives = 3; //목숨 갯수
    var lineNum = 0; 

    //기본 환경 설정 
    var music = "A";
    var bgm = "sound/overworld.mp3";
    var character = "mario";

    var mouseStartX;
    var firstInterval = true;
    var sensivity = 1;
    var isStart = false;
    var clickcount=0;
    var startcount=0;
    var startGame;
    //점수 
    var scoreObj = {
        currScore: 0,
    };
    var bricks; //벽돌 객체
    var chmusic = new Audio(); //캐릭터 선택 음악

    // 뒤에서 쓸 랜덤 숫자 함수
    // start: 시작번호, end: 끝번호
    // start 이상 end 이하의 수를 무작위로 return
    function randomNum(start, end) {
        result = Math.floor(Math.random() * (end - start + 1)) + start;
        return result;
    }

    //음악 관련 객체
    var musicObj = {
        musicOO: "",

        //배경음악
        playMusic: function () {
            this.musicOO = new Audio(bgm);
            if(mVol == 0){
                this.musicOO.volume = mVol;
            }
            this.musicOO.loop = true;
            this.musicOO.play();
        },

        //easy 난이도 배경음악
        playEasy:function(){
            this.musicOO = new Audio("sound/overworld.mp3");
            if(mVol == 0){
                this.musicOO.volume = mVol;
            }
            this.musicOO.loop = true;
            this.musicOO.play();
        },

        //normal 난이도 배경음악
        playNormal:function(){
            this.musicOO = new Audio("sound/underworld.mp3");
            if(mVol == 0){
                this.musicOO.volume = mVol;
            }
            this.musicOO.loop = true;
            this.musicOO.play();
        },

        //hard 난이도 배경음악
        playHard:function(){
            this.musicOO = new Audio("sound/castle.mp3");
            if(mVol == 0){
                this.musicOO.volume = mVol;
            }
            this.musicOO.loop = true;
            this.musicOO.play();
        },

        //엔딩 음악
        playEnding:function(){
            this.musicOO = new Audio("sound/ending.mp3");
            if(mVol == 0){
                this.musicOO.volume = mVol;
            }
            this.musicOO.loop = true;
            this.musicOO.play();
        },

        //마리오 선택시 효과음
        playMario: function () {
            chmusic.src = "sound/mario.mp3";
            chmusic.volume = 0.4;
            chmusic.play();
        },
        //루이지 선택시 효과음
        playLuigi: function () {
            chmusic.src = "sound/luigi.mp3";
            chmusic.volume = 0.6;
            chmusic.play();
        },
        //게임 오버 음악
        playDeath: function () {
            var musicO = new Audio("sound/death.wav");
            musicO.play();
        },

        //벽돌 효과음
        playBrick: function () {
            var musicO = new Audio("sound/break_brick.wav");
            musicO.play();
        },
        //초록버섯 효과음
        playGreenmushroom: function () {
            var musicO = new Audio("sound/greenmushroom.wav");
            musicO.play();
        },
        //빨강버섯 효과음
        playRedmushroom: function () {
            var musicO = new Audio("sound/redmushroom.wav");
            musicO.play();
        },
        //쿠파 효과음
        playKoopa: function () {
            var musicO = new Audio("sound/koopa.wav");
            musicO.play();
        },
        //랜덤 효과음
        playQuestion: function () {
            var musicO = new Audio("sound/question.wav");
            musicO.play();
        },
        //클리어 음악
        playClear: function () {
            var musicO = new Audio("sound/clear.wav");
            musicO.play();
        },
        //배경음악 정지
        stopMusic: function () {
            this.musicOO.pause();
            this.musicOO.currentTime = 0;
        },
        //배경음악 음소거
        muteMusic: function () {
            this.musicOO.volume = mVol;
        },
        //배경음악 음소거 해제
        unmuteMusic: function () {
            this.musicOO.volume = mVol;
        }
    };

    musicObj.playMusic();

    // 블럭 화면에 그려줌
    brickName = ["brick1", "brick2", "mushroomred", "mushroomgreen", "koopa", "question", "peach"];
    function drawBricks() {
        for (var c = 0; c < brickRowCount; c++) {
            for (var r = 0; r < brickColumnCount; r++) {
                //status가 0이면 그리지 않는다.
                // 1: brick1, 2: brick2, 3: mushroomerd, 4: mushroomgreen, 5: koopa, 6: question, 7: peach
                if (bricks[c][r].status != 0) {
                    var brickX = r * brickWidth;
                    var brickY = brickOffsetBottom - c * brickHeight;
                    bricks[c][r].x = brickX;
                    bricks[c][r].y = brickY;
                    var img = new Image();
                    img.src = "img/" + brickName[bricks[c][r].status-1] + ".png";
                    ctx.drawImage(img, brickX, brickY);
                }
            }
        }
    }

    //x축위 시작 위치
    var paddleX = (canvas.width) / 2;

    // 공그리기
    function drawBall() {
        ctx.beginPath();
        ctx.arc(x, y, ballRadius, 0, Math.PI * 2);
        ctx.strokeStyle = "black";
        ctx.lineWidth = 5;
        ctx.stroke();
        ctx.fillStyle = "white";
        ctx.fill();
        ctx.closePath();
    }
    // paddle 그리기
    function drawPaddle() {
        ctx.beginPath();
        ctx.rect(paddleX,canvas.height - paddleHeight,paddleWidth,paddleHeight);
        var img1 = new Image();
        img1.src = "img/" + character + "_right.png";
        ctx.drawImage(img1, paddleX - 33/2, canvas.height - paddleHeight + 10, 33, 44);
        var img2 = new Image();
        img2.src = "img/pipe.png";
        ctx.drawImage(img2, paddleX - paddleWidth/2, canvas.height - paddleHeight, paddleWidth, 10);
        ctx.closePath();
    }
    // setInterval을 이용해 반복되는 함수
    function draw() {
        // 공의 이동을 앞에서 먼저 처리한다 -> 블럭과 공의 충돌 판정에서 문제가 생기는 것을 방지
        if (isStart) {
            x += dx;
            y += dy;
        }
        else {
            x = paddleX;
        }

        //canvas 비우기
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        drawBackground();
        drawBall();
        drawPaddle();
        drawBricks();
        drawScore();
        drawLives();
        collisionDetection();
        //공과 좌우 벽의 충돌 여부 확인
        if (x + dx > canvas.width - ballRadius || x + dx < ballRadius) {
            dx = -dx;
        }

        if (y + dy < ballRadius) { // 천장에 부딪힘
            dy = -dy;
        } 
        
        
        if (y + dy > canvas.height - ballRadius - paddleHeight) {
            if (y + dy > canvas.height - paddleHeight) {
                
            }
            else {
                if (x > paddleX - paddleWidth/2 && x < paddleX + paddleWidth/2) { // paddle에 부딪힘
                    dy = -dy;
                } 
            }
        }

        if (y + dy > canvas.height - ballRadius) { // 바닥에 부딪힘
    	
    		//목숨 감소
            lives--;

            //게임 오버
            if (lives == 0) {
                musicObj.stopMusic();
                musicObj.playDeath();
                clearInterval(startGame);

                firstInterval = true;
                mouseMoveTrigger();
                isStart = false;

                //게임오버 화면 호출
                setTimeout(function(){
                    showOver();
                },4000);
            
            }

            // 재시작 
            else {
                x = canvas.width / 2;
                y = canvas.height - 65;
                dx = 4;
                dy = -4;
                paddleWidth = 100;
                paddleX = canvas.width / 2;
                firstInterval = true;
                mouseMoveTrigger();
                isStart = false;
            }
        }

        function start() {
            $("#my_canvas").off("click");
            isStart = true;
        }

        //클릭시 스타트
        $("#my_canvas").on("click", start);
    }

   // 마우스를 이용한 paddle 움직임
    function mouseMoveHandler(e) {

        var diff = (window.innerWidth - canvas.width) /2

        if (firstInterval) {
            mouseStartX = e.clientX - canvas.offsetLeft;
            firstInterval = false;
        }
        var relativeX = e.clientX - canvas.offsetLeft;
        // 마우스의 초기위치 기준으로 paddle 움직임
        relativeX = (relativeX - mouseStartX) * sensivity;
        paddleX = e.clientX - diff
    }

    function mouseMoveTrigger() {
        $(window).on("mouseover", function (e) {
            mouseStartX = e.clientX - canvas.offsetLeft;
        });
    }

    // 마우스를 이용한 paddle 움직임
    $("#my_canvas").on("mousemove", mouseMoveHandler);

    // 블럭 충돌 감지 함수
    function collisionDetection() {
        for (var c = 0; c < brickRowCount; c++) {
            for (var r = 0; r < brickColumnCount; r++) {
                var b = bricks[c][r];
                // 모든 블럭에 대해서 공과의 위치 비교
                if (b.status != 0) {
                    if (checkCollision(c, r)) { // 공과 블럭이 부딪힌 판정
                        // 1: brick1, 2: brick2, 3: mushroomerd, 4: mushroomgreen, 5: koopa, 6: question, 7: peach
                        switch(b.status) {
                            case 1:
                                scoreObj.currScore+=100;
                                b.status = 0;
                                musicObj.playBrick();
                                break;
                            case 2:
                                scoreObj.currScore+=100;
                                b.status = 1;
                                musicObj.playBrick();
                                break;
                            case 3:
                                // 빨간 버섯
                                scoreObj.currScore+=300;
                                b.status = 0;
                                musicObj.playRedmushroom();
                                if(paddleWidth < 300){
                                    paddleWidth = paddleWidth * 1.2; 
                                }
                                break;
                            case 4:
                                // 초록버섯
                                scoreObj.currScore+=300;
                                b.status = 0;
                                musicObj.playGreenmushroom();
                                dx = dx * 0.85;
                                dy = dy * 0.85;
                                break;
                            case 5:
                                // 쿠파
                                scoreObj.currScore+=50;
                                b.status = 0;
                                musicObj.playKoopa();
                                if (randomNum(0, 1) == 0) {
                                    paddleWidth = paddleWidth * 0.85; 
                                }
                                else {
                                    dx = dx * 1.2;
                                    dy = dy * 1.2;
                                }
                                break;
                            case 6:
                                // 랜덤
                                scoreObj.currScore+=500;
                                b.status = 0;
                                musicObj.playQuestion();
                                switch (randomNum(0, 3)) {
                                    case 0:
                                        if(paddleWidth < 300){
                                            paddleWidth = paddleWidth * 1.2;
                                        }
                                        break;
                                    case 1:
                                        dx = dx * 0.85;
                                        dy = dy * 0.85;
                                        break;
                                    case 2:
                                        paddleWidth = paddleWidth * 0.85; 
                                        break;
                                    case 3:
                                        dx = dx * 1.2;
                                        dy = dy * 1.2;
                                        break;
                                }
                                break;
                            case 7:
                                // 피치
                                // 여기서 승리하고 다음 스테이지로 이동
                                // replay, menu, next 중에서 선택
                                scoreObj.currScore+=1000;
                                firstInterval = true;
                                mouseMoveTrigger();
                                isStart = false;
                                musicObj.stopMusic();
                                musicObj.playClear();
                                clearInterval(startGame);
                                setTimeout(function(){
                                    showClear();
                                },7000);
                                break;
                        }

                        // 블럭들을 한줄 내리기 위한 코드
                        var result = 0;
                        for (var i = 0; i < brickColumnCount; i++) {
                            result = result + bricks[lineNum][i].status; // 블럭들의 status 총합
                        }
                        if (result == 0) { // 한 줄의 블럭들의 status가 모두 0인경우 빈 줄이므로 한줄 내리기
                        	//피치가 보이는 경우 내리지 않음
                            if(bricks[0][0].y != 0){
                                if(bricks[brickRowCount-1][0].y != 0){
                                    lineNum++;
                                    brickOffsetBottom += brickHeight;
                                    y += brickHeight;
                                }
                            }
                        }
                    }
                }
            }
        }

        //블록 충돌 체크
        function checkCollision(c, r) {
            if(bricks[c][r].y>=0){
                if (Math.abs(y - ballRadius - (bricks[c][r].y + brickHeight)) < Math.abs(dy) && x > bricks[c][r].x && x < bricks[c][r].x + brickWidth) {
                    // 블럭기준 아래        
                    dy = -dy;
                    return true;    
                }
                else if (Math.abs(y + ballRadius - (bricks[c][r].y)) < Math.abs(dy) && x > bricks[c][r].x && x < bricks[c][r].x + brickWidth) {
                    // 블럭기준 위        
                    dy = -dy;
                    return true;    
                }
                else if (Math.abs(x - ballRadius - (bricks[c][r].x + brickWidth)) < Math.abs(dx) && y > bricks[c][r].y && y < bricks[c][r].y + brickHeight) {
                    // 블럭기준 오른쪽
                    dx = -dx;
                    return true;
                }
                else if (Math.abs(x + ballRadius - (bricks[c][r].x)) < Math.abs(dx) && y > bricks[c][r].y && y < bricks[c][r].y + brickHeight) {
                    // 블럭기준 왼쪽
                    dx = -dx;
                    return true;
                }
                else if (Math.pow(x-bricks[c][r].x, 2)+Math.pow(y-bricks[c][r].y, 2)<Math.pow(ballRadius,2)) {
                    // 블럭기준 왼쪽 위 꼭짓점
                    if (dx > 0 && dy > 0) {
                        dx = -dx;
                        dy = -dy;
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else if (Math.pow(x-(bricks[c][r].x+brickWidth), 2)+Math.pow(y-bricks[c][r].y, 2)<Math.pow(ballRadius,2)) {
                    // 블럭기준 오른쪽 위 꼭짓점
                    if (dx < 0 && dy > 0) {
                        dx = -dx;
                        dy = -dy;
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else if (Math.pow(x-bricks[c][r].x, 2)+Math.pow(y-(bricks[c][r].y+brickHeight), 2)<Math.pow(ballRadius,2)) {
                    // 블럭기준 왼쪽 아래 꼭짓점
                    if (dx > 0 && dy < 0) {
                        dx = -dx;
                        dy = -dy;
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else if (Math.pow(x-(bricks[c][r].x+brickWidth), 2)+Math.pow(y-(bricks[c][r].y+brickHeight), 2)<Math.pow(ballRadius,2)) {
                    // 블럭기준 오른쪽 아래 쪽짓점
                    if (dx < 0 && dy < 0) {
                        dx = -dx;
                        dy = -dy;
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
    }

    // 점수표시
    function drawScore() {
        ctx.font = "25px SuperMario256";
        ctx.fillStyle = "yellow";
        score_str = scoreObj.currScore + "";
        zeros = new Array(8 - score_str.length + 1).join("0");
        ctx.fillText(zeros + score_str, canvas.width - 130, canvas.height - 25);
    }

    //목숨 표시
    function drawLives() {
        var img = new Image();
        img.src = "img/" + character + "_life.png";
        ctx.drawImage(img,10,canvas.height-50,45,30);
        ctx.font="30px SuperMario256";
        ctx.fillStyle = "white";
        ctx.fillText(" x " + lives, 50, canvas.height - 25);
        ctx.font="30px SuperMario256";
        ctx.strokeStyle = "black";
        ctx.lineWidth=2.5;
        ctx.strokeText(" x " + lives, 50, canvas.height - 25);
    }

    //배경이미지 그리기
    var bgimg = new Image();
    function drawBackground() {
        ctx.drawImage(bgimg, 0, 40, 840, 600, 0, 0, 840, 600);
    }

    // 메뉴들에 대한 클릭 이벤트
    // setup의 경우
    $("#main_menu div h1").eq(0).on("click", clickSetup);

    // play의 경우
    $("#main_menu div h1").eq(1).on("click", clickPlay);

    // help의 경우
    $("#main_menu div h1").eq(2).on("click", clickHelp);

    // back의 경우
    $("#back").on("click", clickBack);

    //setup 화면
    function clickSetup() {
        // event listener 지우기
        $("#main_menu div h1").eq(0).off("click", clickSetup);
        $("#main_menu div h1").eq(1).off("click", clickPlay);
        $("#main_menu div h1").eq(2).off("click", clickHelp);
        // 화면 바꿔치기
        $("#main_menu").hide();
        $("#back").show();
        $("#setup").show();


        // music이 뭐가 선택되었냐에 따라서 배경색 노랑으로 바꾸기
        var button1 = $("#setup .selection_container:nth-of-type(1) .selection:nth-of-type(1)");
        var button2 = $("#setup .selection_container:nth-of-type(1) div.selection:nth-of-type(2)");
        var button3 = $("#setup .selection_container:nth-of-type(2) div.selection:nth-of-type(1)");
        var button4 = $("#setup .selection_container:nth-of-type(2) div.selection:nth-of-type(2)");
        if (music == "A") {
            button1.css("background-color", "yellow");
        }
        else if (music == "B") {
            button2.css("background-color", "yellow");
        }
        
        // character가 뭐가 선택되었냐에 따라서 배경색 노랑으로 바꾸기
        if (character == "mario") {
            button3.css("background-color", "yellow");
        }
        else if (character == "luigi") {
            button4.css("background-color", "yellow");
        }

        // 각각의 버튼에 대한 클릭이벤트들(music, character 변수값 변경 및 버튼의 배경색 변경)
        button1.on("click", function () {
            music = "A";
            musicObj.stopMusic();
            bgm = "sound/overworld.mp3";
            musicObj.playMusic();
            button1.css("background-color", "yellow");
            button2.css("background-color", "gray");
            console.log("music: " + music + ", chracter: " + character);
        });

        button2.on("click", function () {
            music = "B";
            musicObj.stopMusic();
            bgm = "sound/underwater.mp3";
            musicObj.playMusic();
            button2.css("background-color", "yellow");
            button1.css("background-color", "gray");
            console.log("music: " + music + ", chracter: " + character);
        });

        button3.on("click", function () {
            character = "mario";
            musicObj.playMario();
            button3.css("background-color", "yellow");
            button4.css("background-color", "gray");
            console.log("music: " + music + ", chracter: " + character);
        });

        button4.on("click", function () {
            character = "luigi";
            musicObj.playLuigi();
            button4.css("background-color", "yellow");
            button3.css("background-color", "gray");
            console.log("music: " + music + ", chracter: " + character);
        });
    }

    //play 화면 
    function clickPlay(e) {
        //event listener 지우기
        $("#main_menu div h1").eq(0).off("click", clickSetup);
        $("#main_menu div h1").eq(1).off("click", clickPlay);
        $("#main_menu div h1").eq(2).off("click", clickHelp);
        // 화면 바꿔치기
        $("#main_menu").hide();
        $("#back").show();
        $("#difficulty").show();

        if(clickcount == 0){
            $("#difficulty div h1").each(function (index, item) { 
                $(item).on("click", clickDifficulty);
                clickcount++;
            });
        }
    }

    //help 화면
    function clickHelp() {
        // event listener 지우기
        $("#main_menu div h1").eq(0).off("click", clickSetup);
        $("#main_menu div h1").eq(1).off("click", clickPlay);
        $("#main_menu div h1").eq(2).off("click", clickHelp);
        // 화면 바꿔치기
        $("#main_menu").hide();
        $("#back").show();
        $("#help").show();
    }

    //back 버튼 클릭
    function clickBack() {
    	
        // event listener 지우기
        $("#main_menu div h1").eq(0).off("click", clickSetup);
        $("#main_menu div h1").eq(1).off("click", clickPlay);
        $("#main_menu div h1").eq(2).off("click", clickHelp);
        // 화면 바꿔치기
        $("#back").hide();
        $(".menu").hide();
        $("#main_menu").show();
        
        $("#main_menu div h1").eq(0).on("click", clickSetup);
        $("#main_menu div h1").eq(1).on("click", clickPlay);
        $("#main_menu div h1").eq(2).on("click", clickHelp);
    }

    //난이도 클릭
    function clickDifficulty () {
        // 난이도에 따른 변수변경
        difficultyObj.setDiff($(this).text());
        
        // event listener 지우기
        $("#difficulty div h1").each(function (index, item) { 
            $(item).off("click", clickDifficulty);
        });

        $("#difficulty").hide();
        $("my_canvas").show();

        //$("body").css("cursor", "none");
        $("#back").hide();
        // 클릭한 후 어거지로 초기화
        firstInterval = true;
        mouseMoveTrigger();

        // 난이도에 따라 블럭들 할당
        if($(this).text()=="EASY"){
            bgimg.src = "bg/background_game.jpg";
            musicObj.stopMusic();
            musicObj.playEasy();
            allocateBlocks1();
        }
        else if($(this).text()=="NORMAL"){
            bgimg.src = "bg/background_game2.jpg";
            musicObj.stopMusic();
            musicObj.playNormal();
            allocateBlocks2();
        }
        else if($(this).text()=="HARD"){
            bgimg.src = "bg/background_game3.jpg";
            musicObj.stopMusic();
            musicObj.playHard();
            allocateBlocks3();
        }
        scoreObj.currScore = 0;
        scoreObj.easyScore = 0;
        scoreObj.normalScore = 0;
        scoreObj.hardScore = 0;
        startGame = setInterval(draw, 10); 
    }

    //클리어 화면 
    function showClear() {
        $("my_canvas").hide();
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        $("#clear").show();

        $("#clear div #score").eq(0).text("Current Score : " + scoreObj.currScore);
        $("#clear div h1").eq(1).on("click", clickReplay);
        $("#clear div h1").eq(2).on("click", clickNext);
        $("#clear div h1").eq(3).on("click", clickMenu);

        if(brickRowCount==6){
            $("#clear div h1").eq(3).hide();
        }
        else{
        	$("#clear div h1").eq(3).show();
        }
    }

    //게임 오버 화면 
    function showOver() {
        $("my_canvas").hide();
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        $("#game_over").show();
        $("#game_over div #score").eq(0).text("Total Score : " + scoreObj.currScore);
        $("#game_over div h1").eq(1).on("click", clickReplay);
        $("#game_over div h1").eq(2).on("click", clickMenu);
    }

    //클리어 후 replay
    function clickReplay() {

    	// event listener 지우기
        $("#clear div h1").eq(1).off("click");
        $("#clear div h1").eq(2).off("click");
        $("#clear div h1").eq(3).off("click");
        $("#game_over div h1").eq(1).off("click");
        $("#game_over div h1").eq(2).off("click");

        $("#clear").hide();
        $("#game_over").hide();
        $("my_canvas").show();

        //변수 초기화
        x = canvas.width / 2;
        y = canvas.height - 60;
        dx = 4;
        dy = -4;
        ballRadius = 10;
        paddleHeight = 54;
        paddleWidth = 100;
        brickOffsetBottom = 180;
        lineNum = 0;
        scoreObj.currScore = 0;
        lives = 3;
        firstInterval = true;
        mouseMoveTrigger();

        // 블럭들 할당
        //easy 난이도
        if(brickRowCount == 4){
            bgimg.src = "bg/background_game.jpg";
            musicObj.playEasy();
            allocateBlocks1();
        //normal 난이도
        }else if(brickRowCount == 5){
            bgimg.src = "bg/background_game2.jpg";
            musicObj.playNormal();
            allocateBlocks2();
        //hard 난이도
        }else{
            bgimg.src = "bg/background_game3.jpg";
            musicObj.playHard();
            allocateBlocks3();
        }
        startGame = setInterval(draw, 10);
    }

    //클리어 후 next
    function clickNext () {

        // event listener 지우기
        $("#clear div h1").eq(1).off("click");
        $("#clear div h1").eq(2).off("click");
        $("#clear div h1").eq(3).off("click");
        $("#game_over div h1").eq(1).off("click");
        $("#game_over div h1").eq(2).off("click");

        $("#clear").hide();
        $("my_canvas").show();

        //변수 초기화
        x = canvas.width / 2;
        y = canvas.height - 60;
        dx = 4;
        dy = -4;
        ballRadius = 10;
        paddleHeight = 54;
        paddleWidth = 100;
        brickOffsetBottom = 180;
        lineNum = 0;
        firstInterval = true;
        mouseMoveTrigger();

        // 블럭들 할당
        //easy -> normal
        if(brickRowCount == 4){
            difficultyObj.setDiff("NORMAL");
            bgimg.src = "bg/background_game2.jpg";
            musicObj.playNormal();
            allocateBlocks2();
            startGame = setInterval(draw, 10);
        }
		//normal -> hard
        else if(brickRowCount == 5){
            difficultyObj.setDiff("HARD");
            bgimg.src = "bg/background_game3.jpg";
            musicObj.playHard();
            allocateBlocks3();
            startGame = setInterval(draw, 10); 
        }
		//hard단계 클리어
        else if(brickRowCount == 6){
        	//올 클리어 화면 
            $("my_canvas").hide();
            $("#all_clear").show();
            $("#all_clear div #score").eq(0).text("Total Score : " + scoreObj.currScore);
            $("#all_clear div h1").eq(1).on("click", clickMenu);
            
            var color = ["tomato", "springgreen", "skyblue", "orange", "violet"];
            var shadow = ["darkred", "green", "blue", "chocolate", "indigo"];
            var a=1;
            
            $("#all_clear h2").css({color: color[0], "text-shadow":"5px 5px 10px "+shadow[0]});
            var changeColor = setInterval(function(){
	            $("#all_clear h2").css({color: color[a], "text-shadow":"5px 5px 10px "+shadow[a]});
	            a++;
	            if(a==5){
	                a=0;
	            }
	        },400);
            musicObj.playEnding();
        }
    }

    //클리어 후 메뉴
    function clickMenu () {

        // event listener 지우기
        $("#clear div h1").eq(1).off("click");
        $("#clear div h1").eq(2).off("click");
        $("#clear div h1").eq(3).off("click");
        $("#game_over div h1").eq(1).off("click");
        $("#game_over div h1").eq(2).off("click");
        $("#all_clear div h1").eq(1).off("click");

        $("#clear").hide();
        $("#game_over").hide();
        $("#all_clear").hide();

        ctx.clearRect(0, 0, canvas.width, canvas.height);
        $("my_canvas").hide();

        //변수 초기화
        x = canvas.width / 2;
        y = canvas.height - 60;
        dx = 4;
        dy = -4;
        ballRadius = 10;
        paddleHeight = 54;
        paddleWidth = 100;
        brickRowCount = 10;
        brickColumnCount = 7;
        brickWidth = 120;
        brickHeight = 60;
        brickPadding = 0;
        brickOffsetTop = 0;
        brickOffsetLeft = 0;
        brickOffsetBottom = 180;
        scoreObj.currScore = 0;
        scoreObj.easyScore = 0;
        scoreObj.normalScore = 0;
        scoreObj.hardScore = 0;
        lives = 3;
        lineNum = 0;
        firstInterval = true;
        sensivity = 2;
        isStart = false;
        clickcount=0;
        mouseMoveTrigger();
        $("#main_menu").show();
        $("#main_menu div h1").eq(0).on("click", clickSetup);
        $("#main_menu div h1").eq(1).on("click", clickPlay);
        $("#main_menu div h1").eq(2).on("click", clickHelp);
        musicObj.stopMusic();
        musicObj.playMusic();
    }

    // 2차원 배열 table 선언 - 열(c) 행(R) 블럭의 행,열에 대한 이차원 배열 삽입 (벽돌만들기)
    // blockRowcount, blockColumnCount를 이용해 조절 가능
    function allocateBlocks1() {
        
        //벽돌 배열 초기화
        bricks = [];

        //개수 카운트 변수
        var koopa=0;
        var gmush = 0;
        var rmush = 0;
        var random = 0;

        for (var c = 0; c < brickRowCount; c++) {
            bricks[c] = [];
            for (var r = 0; r < brickColumnCount; r++) {
                bricks[c][r] = {
                    x: 0,
                    y: 0,
                    status: randomNum(1, 6) // 피치블럭을 제외한 블럭들 무작위로 생성
                };

                var b = bricks[c][r];

                if (b.status == 2) {
                    b.status=1;
                }else if (b.status == 3) {
                    rmush++;
                }else if (b.status == 4) {
                    gmush++;
                }else if (b.status == 5) {
                    koopa++;
                }else if (b.status == 6) {
                    random++;
                }

                //줄마다 블록들 개수 설정
                if(koopa>1 || rmush > 1 || gmush > 1 || random > 1){
                    if (b.status == 5 && koopa > 1) {
                        b.status=1;
                        if(rmush<=1){
                            b.status = 3;
                            rmush++;
                        }
                    }
                    if (b.status == 3 && rmush > 2) {
                        b.status=1;
                        if(rmush<=1){
                            b.status = 3;
                            rmush++;
                        }
                    }
                    if (b.status == 4 && gmush > 1) {
                        b.status=1;
                        if(rmush<=1){
                            b.status = 3;
                            rmush++;
                        }
                    }
                    if (b.status == 6 && random > 1) {
                        b.status=1;
                        if(rmush<=1){
                            b.status = 3;
                            rmush++;
                        }
                    }   	
                }
            }
            //줄마다 초기화
            koopa=0;
            gmush = 0;
            rmush = 0;
            random = 0;
        }  
        var num = randomNum(0, brickColumnCount-1);
        bricks[brickRowCount-1][num].status = 7; // 맨 위에 피치블럭 하나 배치
    }

    function allocateBlocks2() {

        //벽돌 배열 초기화
        bricks = [];

        //개수 카운트 변수
        var koopa=0;
        var gmush = 0;
        var rmush = 0;
        var random = 0;

        for (var c = 0; c < brickRowCount; c++) {
            bricks[c] = [];
            for (var r = 0; r < brickColumnCount; r++) {
                bricks[c][r] = {
                    x: 0,
                    y: 0,
                    status: randomNum(1, 6) // 피치블럭을 제외한 블럭들 무작위로 생성
                };
                var b = bricks[c][r];
                if (b.status == 3) {
                    rmush++;
                }else if (b.status == 4) {
                    gmush++;
                }else if (b.status == 5) {
                    koopa++;
                }else if (b.status == 6) {
                    random++;
                }
                //줄마다 블록들 개수 설정
                if(koopa>2 || rmush > 2 || gmush > 1 || random > 1){
                    if (b.status == 5 && koopa > 2) {
                        b.status=randomNum(1, 2);
                    }
                    if (b.status == 3 && rmush > 2) {
                        b.status=randomNum(1, 2);
                        if(koopa<=1){
                            b.status = 5;
                            koopa++;
                        }
                    }
                    if (b.status == 4 && gmush > 1) {
                        b.status=randomNum(1, 2);
                        if(koopa<=1){
                            b.status = 5;
                            koopa++;
                        }
                    }
                    if (b.status == 6 && random > 1) {
                        b.status=randomNum(1, 2);
                        if(koopa<=1){
                            b.status = 5;
                            koopa++;
                        }
                    }   	
                }
            }
            //줄마다 초기화
            koopa=0;
            gmush = 0;
            rmush = 0;
            random = 0;
        }  
        var num = randomNum(0, brickColumnCount-1);
        bricks[brickRowCount-1][num].status = 7; // 맨 위에 피치블럭 하나 배치
    }

    function allocateBlocks3() {
           
        //벽돌 배열 초기화
        bricks = [];

        //개수 카운트 변수
        var koopa=0;
        var gmush = 0;
        var rmush = 0;
        var random = 0;

        for (var c = 0; c < brickRowCount; c++) {
            bricks[c] = [];
            for (var r = 0; r < brickColumnCount; r++) {
                bricks[c][r] = {
                    x: 0,
                    y: 0,
                    status: randomNum(2, 6) // 피치블럭을 제외한 블럭들 무작위로 생성
                };
                var b = bricks[c][r];
                if (b.status == 3) {
                    rmush++;
                }else if (b.status == 4) {
                    gmush++;
                }else if (b.status == 5) {
                    koopa++;
                }else if (b.status == 6) {
                    random++;
                }
                //줄마다 블록들 개수 설정
                if(koopa>3 || rmush > 1 || gmush > 1 || random > 1){
                    if (b.status == 5 && koopa > 3) {
                        b.status=2;
                        if(koopa<=2){
                            b.status = 5;
                            koopa++;
                        }
                    }
                    if (b.status == 3 && rmush > 1) {
                        b.status=2;
                        if(koopa<=2){
                            b.status = 5;
                            koopa++;
                        }
                    }
                    if (b.status == 4 && gmush > 1) {
                        b.status=2;
                        if(koopa<=2){
                            b.status = 5;
                            koopa++;
                        }
                    }
                    if (b.status == 6 && random > 1) {
                        b.status=2;
                        if(koopa<=2){
                            b.status = 5;
                            koopa++;
                        }
                    }   	
                }
            }
            //줄마다 초기화
            koopa=0;
            gmush = 0;
            rmush = 0;
            random = 0;
        }  
        var num = randomNum(0, brickColumnCount-1);
        bricks[brickRowCount-1][num].status = 7; // 맨 위에 피치블럭 하나 배치
    }

    //난이도 설정 오브젝트
    // setDiff(diff), diff: (String) EASY, NORMAL, HARD, difficultyObj.currDiff만을 올바른 입력값으로 받는다
    var difficultyObj = {
        currDiff: "",
        setDiff: function(diff) {
            if (diff == "EASY") {
                brickRowCount = 4;
                currDiff = diff;
            }
            else if (diff == "NORMAL") {
                brickRowCount = 5;
                currDiff = diff;
            }
            else if (diff == "HARD") {
                brickRowCount = 6;
                currDiff = diff;
            }
        }    
    };

    //도움말 부분 JS
    var page = 1; //도움말 부분 페이지
    var np = document.getElementById("nextpg");
    var pp = document.getElementById("prevpg");
    var helpdivs1 = document.getElementsByClassName("helpdiv1");
    var helpdivs2 = document.getElementsByClassName("helpdiv2");
    var helpdivs3 = document.getElementsByClassName("helpdiv3");
    np.onclick = nextPage;
    pp.onclick = prevPage;

    //도움말의 다음 페이지로 이동
    function nextPage() {
        var len;
        if(page == 1) {
            pp.style.display = "inline";
            document.getElementById("helptext").style.display = "none";
            len = helpdivs1.length;
            for(var i = 0; i < len; i++) 
                helpdivs1[i].style.display = "none";
            len = helpdivs2.length;
            for(var i = 0; i < len; i++) 
                helpdivs2[i].style.display = "block";
            page++;
        }
        else if(page == 2) {
            np.style.display = "none";
            len = helpdivs2.length;
            for(var i = 0; i < len; i++) 
                helpdivs2[i].style.display = "none";
            len = helpdivs3.length;
            for(var i = 0; i < len; i++) 
                helpdivs3[i].style.display = "block";
            page++;
        }
    }
    //도움말의 이전 페이지로 이동
    function prevPage() {
        if(page == 2) {
            pp.style.display = "none";
            document.getElementById("helptext").style.display = "block";
            len = helpdivs2.length;
            for(var i = 0; i < len; i++) 
                helpdivs2[i].style.display = "none";
            len = helpdivs1.length;
            for(var i = 0; i < len; i++) 
                helpdivs1[i].style.display = "block";
            page--;
        }
        else if(page == 3) {
            np.style.display = "inline";
            len = helpdivs3.length;
            for(var i = 0; i < len; i++) 
                helpdivs3[i].style.display = "none";
            len = helpdivs2.length;
            for(var i = 0; i < len; i++) 
                helpdivs2[i].style.display = "block";
            page--;
        }
    }

    //음악 볼륨 제어
    var volume = document.getElementById("volume");
    var mVol = 0.5;
    volume.onclick = vControl;
    function vControl() {
    	//음소거 해제
        if($("#volume").attr("src") == "img/v_mute.png"){
            $("#volume").attr("src","img/v_unmute.png");
            mVol = 0.5;
            musicObj.unmuteMusic();
        }
        //음소거
        else if($("#volume").attr("src") == "img/v_unmute.png"){
            $("#volume").attr("src","img/v_mute.png");
            mVol = 0;
            musicObj.muteMusic();
        }
    }
});