/* globals jQuery, document */
(function($, undefined) {
    "use strict";

    var $document = $(document);

    $document.ready(function() {

        // highlight.js
        hljs.initHighlightingOnLoad();

        // fitvids.js
        var $postContent = $(".post-content");
        $postContent.fitVids();

        // tocbot.js
        tocbot.init({
            // Where to render the table of contents.
            tocSelector: '.js-toc',
            // Where to grab the headings to build the table of contents.
            contentSelector: '.js-toc-content',
            // Which headings to grab inside of the contentSelector element.
            headingSelector: 'h3, h4, h5',
        });

        // Add class for table
        $('.post-content').children('table').addClass("table table-bordered table-striped");

    });

})(jQuery);
