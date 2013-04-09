$(document).ready(function() {
  var base_path     = 'http://bbtv/';
  var target = null;

  $('.contestant').each(function(i, el) {
    el = $(el);

    el.click(function() {
      // ensure the details block contains the competitor's name and is
      // visible
      var name = $('.name', el).html();
      $('.details .name').html(name);
      $('.details').css('display', 'block');

      // hide the intro block
      $('.none').css('display', 'none');

      // log the target id so we can use it in the ajax call
      target = $(el).attr('id');
    
      // remove selected class from all contestants & add it to the current one
      $('.contestant').removeClass('selected');
      el.addClass('selected');
    });

    // process input
    $('input.inc').click(function() {
      if (target) {
        // run request to update the score and update with new value
        $.ajax({
          url: base_path + '?target=' + target
        }).done(function(new_score) {
          $('#' + target + ' .score').html(new_score);
        });
      }
    });
  });
});