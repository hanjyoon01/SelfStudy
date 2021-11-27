var i=0;
var index=0;
var imgArray = ["img1.jpg","img2.jpg","img3.jpg","img4.jpg","img5.jpg","img6.jpg"];

$(document).ready(function(){

	$("div.out").mouseover(function(){
		$("p:first",this).text("mouse over");
		$("p:last",this).text(++i);
	});

	$("div.out").mouseout(function(){
		$("p:first",this).text("mouse out");
	});

	$("#b1").on("click", 
	{url:"http://www.google.com", 
	winattributes:"resize=1, scrollbars=1, status=1"}, max_open);

	$("#bind").click(function(){
		$("body")
		.on("click","#theone",flash)
		.find("#theone")
		.text("Can Click!");
	});

	$("#unbind").click(function(){
		$("body")
		.off("click","#theone",flash)
		.find("#theone")
		.text("Does nothing...");
	});

	$("#trigger_test button:first").click(function(){
		update($("span:first"));
	})

	$("#trigger_test button:last").click(function(){
		$("#trigger_test button:first").trigger("click");
		update($("span:last"));
	})

	$("#image").click(function(){
		if($("#image").attr("src") == "img1.png"){
			$("#image").attr("src","img2.png")
		}
		else{
			$("#image").attr("src","img1.png")
		}
	})

	$("#imgAlbum").attr("src", imgArray[index])
	$("#imgAlbum").click(function(){
		index++;
		$("#imgAlbum").attr("src", imgArray[index])
		if(index==6){
			index=0;
		}
		$("#imgAlbum").attr("src", imgArray[index])
	});

	$(".main-menu").mouseover(function(){
		$(this).css({fontSize:"20", backgroundColor:"green"})
	});

	$(".main-menu").mouseout(function(){
		$(this).css({fontSize:"16",background:"none"})
	});

	$("#add_img img").on("click",show_note_form);
	$("#add_note").on("click",push_note);
	$(window).resize(function(){
		change_position($(".popup"));
	});

	$("#moving_button").click(function(){
		$("#moving_box").animate(
		{
			right:'0px',
			height:'+=50px',
			width:'+=50px'
		});

		$("#animation_test").animate(
		{
			height:'+=50px'
		});
	});

	$(".accordion").each(function(){
		var dl = $(this);
		var alldd = dl.find("dd");
		var alldt = dl.find("dt");
		function closeAll(){
			alldd.addClass("closed");
			alldt.addClass("closed");
		}
		function open(dt,dd ){
			dd.removeClass("closed");
			dt.removeClass("closed");
		}
		alldt.css("cursor","pointer");
		alldd.hide();
		closeAll();
		alldt.click(function(){
			alldd.hide();
			var dt = $(this);
			var dd = dt.next();
			closeAll();
			open(dt,dd);
			dd.show();
			alldt.css("cursor","pointer");
			dt.css("cursor","default");
		});
	});

	var interval=3000;
	$('.slideshow').each(function(){
		var timer;
		var container = $(this);
		function switchImg(){
			 var imgs = container.find('img');
			 var first = imgs.eq(0);
			 var second = imgs.eq(1);
			 first.appendTo(container).fadeOut(2000);
			 second.fadeIn();
		}
		function startTimer(){
			timer = setInterval(switchImg,interval);
		}
		function stopTimer(){
			clearInterval(timer);
		}
		container.hover(stopTimer,startTimer);
		startTimer();
	});

	$("#getText").click(function(){
		$("#textbox").text("글자 입력 테스트");
		var req = $.ajax("data.txt");
		req.done(function(data,status){
			var students = JSON.parse(data);
			for(var i=0;i<students.length;i++){
				var str="<br>"+students[i].name;
				$("#textbox").append(str);
			}
		});
	});

	$("#getText2").click(function(){
		var req = $.ajax("data.json");
		req.done(function(data,status){
			var tb=$("<table/>");
			var row = $("<tr/>").append(
				$("<th/>").text("이름"),
				$("<th/>").text("아이디"),
				$("<th/>").text("학과"),
				$("<th/>").text("수강과목")
			);
			tb.append(row);
			for(var i=0;i<data.length;i++){
				var name = data[i].name;
				var id = data[i].id;
				var dept = data[i].department;
				var cls = data[i].class;
				var sub= '';
				for(var j=0;j<cls.length;j++){
					if(j<(cls.length-1)){
						sub+=cls[j]+', ';
					}
					else{
						sub+=cls[j];
					}
				}
				var phone = data[i].phone;
				var row = $("<tr/>").append(
					$("<td/>").text(name),
					$("<td/>").text(id),
					$("<td/>").text(dept),
					$("<td/>").text(sub)
				);
				tb.append(row);
			}
			$("#textbox").html(tb);
		});
	});
});

function max_open(event){
	var maxwindow = window.open(event.data.url,"",event.data.winattributes);
	maxwindow.moveTo(0,0);
	maxwindow.resizeTo(screen.availWidth,screen.availHeight); 	
}

function flash(){
	$("#off_test").show().fadeOut("slow");
}

function update(j){
	var n = parseInt(j.text(),10);
	j.text(n+1);
}

function show_note_form(){
	$("#note_form").addClass("popup");
	change_position($(".popup"));
	$("#note_form").fadeIn(1000);
}

function push_note(){
	var title = $("#note_title").val();
	var date = $("#note_date").val();
	var content = $("#note_content").val();
	var str = "<p>"+title+"<br>"+date+"<br>"+content+"</p><br>";
	$("#note_form").fadeOut(1000);
	$("#note").append(str);
}

function change_position(obj){
	var l = ($(window).width() - obj.width())/2;
	var t = ($(window).height() - obj.height())/2;
	obj.css({top:t, left:l});
}