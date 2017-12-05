$(document).ready(function(){
	$("#footer-button").mouseenter(function(){
		$("#footer-button").animate({
			fontSize: '+=2em'
		});
	});
	$("#footer-button").mouseleave(function(){
		$("#footer-button").animate({
			fontSize: '-=2em'}, "fast"
		);
	})
});