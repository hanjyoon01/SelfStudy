//202011390 한재윤

$(document).ready(function(){
	
	function addIMG(){
		$("#container").append("<img src=\"me.png\"/>");
	}
	addIMG();
	function moveIMG(){
		var d = $("#container").find("img");
		var first = d.eq(0);
		first.appendTo($("#container"));

		$("#container img").eq(0).css({opacity : 0.25});
		$("#container img").eq(1).css({opacity : 1});
		$("#container img").eq(2).css({opacity : 0.25});
		$("#container img").eq(0).show();
		$("#container img").eq(1).show();
		$("#container img").eq(2).show();
		$("#container img").eq(3).hide();
	}
	moveIMG();
	setInterval(moveIMG,2000);


	$(".menu").eq(0).on("click", oath);
	
	function oath(){
		$("#content").empty();
		var str = "<p>나 <b>한재윤(202011390)</b>은<br>2021년 <b>웹 프로그레밍 기말고사 온라인 시험을 수행</b>함에 있어서<br>양심을 걸고 <b>정직하고 올바른 방법으로 수행함을 약속</b>합니다</p>";
		$("#content").append(str);
		$("#content").css("text-align","center");
	}

	$(".menu").eq(1).on("click", getNews);
	
	function getNews(){
		$("#content").empty();

		var req = $.ajax({
			url: "/rss",
			dataType:"xml"
		});
		$("#content").append("<dl>");
		req.done(function(data){
			var items = $(data).find("item");
			if(items.length>0){
				items = items.slice(0,5);
				items.each(function(){
					var item = $(this);
					var title = item.find("title").text();
					var description = item.find("description").text();
					var t = "<dt>"+ title +"</dt>";
					var d = "<dd>"+ description +"</dd>";
					$("#content").append(t);
					$("#content").append(d);
				});
			}
		});
		req.fail(function(jqXHR,textStatus){
			alert("failed: "+textStatus);
		});
		$("#content").append("</dl>");
		$("#content dl").hide();
	}
});