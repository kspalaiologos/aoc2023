#!/bin/dyalogscript
s←'#'=↑⊃⎕nget'input.txt'1
f←{(+\⍵)++\⍺×~⍵}⋄o←⍸s⋄⎕pp←34
sol←{
  h←⍵f∨/s⋄v←⍵f∨⌿s
  a←∘.{x←↑⍺⍵⋄h[x[;1]]+⍥(|-/)v[x[;2]]}⍨o
  +/,(⊢×∘.<⍨∘⍳∘≢)a}
⎕←sol 2⋄⎕←sol 1E6