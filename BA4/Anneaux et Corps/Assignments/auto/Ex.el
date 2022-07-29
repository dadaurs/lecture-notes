(TeX-add-style-hook
 "Ex"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt" "a4paper")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("babel" "francais")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "inputenc"
    "fontenc"
    "babel"
    "lmodern"
    "amsmath"
    "amssymb"
    "amsthm"))
 :latex)

