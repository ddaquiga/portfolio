$(document).ready(function(){
	$("#footer-button").mouseenter(function(){
		$("#footer-button").animate({
			fontSize: '+=1em'}, "fast"
		);
	});
	$("#footer-button").mouseleave(function(){
		$("#footer-button").animate({
			fontSize: '-=1em'}, "fast"
		);
	})
});