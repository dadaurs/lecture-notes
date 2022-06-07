(TeX-add-style-hook
 "preamble"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "hidelinks")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("tcolorbox" "most") ("babel" "french") ("ntheorem" "amsmath" "hyperref" "thmmarks") ("fontawesome5" "fixed")))
   (add-to-list 'LaTeX-verbatim-environments-local "lstlisting")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "href")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "inputenc"
    "fontenc"
    "textcomp"
    "hyperref"
    "amsmath"
    "bookmark"
    "float"
    "graphicx"
    "mdframed"
    "tcolorbox"
    "babel"
    "bbm"
    "verbatim"
    "varioref"
    "theoremref"
    "tikz"
    "tikz-cd"
    "listings"
    "faktor"
    "python"
    "xurl"
    "xcolor"
    "ntheorem"
    "fontawesome5"
    "imakeidx"
    "import"
    "xifthen"
    "pdfpages"
    "transparent"
    "thmtools"
    "amssymb"
    "aligned-overset"
    "stmaryrd"
    "subfiles")
   (TeX-add-symbols
    '("lecture" 3)
    "mathnote")
   (LaTeX-add-mdframed-mdtheorems
    '("propr" "new"))
   (LaTeX-add-xcolor-definecolors
    "background"
    "myred"
    "mygreen"
    "myyellow"
    "myblue"
    "mymagenta"
    "mycyan"
    "mygray")
   (LaTeX-add-listings-lstdefinestyles
    "mystyle")
   (LaTeX-add-ntheorem-newtheorems
    "thm"
    "defn"
    "propo"
    "crly"
    "lemma"
    "axiom"
    "exo"))
 :latex)

