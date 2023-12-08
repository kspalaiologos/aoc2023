#!/bin/dyalogscript
⎕io ⎕pp←0 34⋄l←⊃⎕NGET'input.txt'1
b←'LR'⍳⊃l⋄m←↑{⍵⊆⍨⎕a∊⍨⍵}¨2↓l⋄h←1500⌶m[;0]
t←{'Z'=⊃⌽⍵:⍺⋄(⍺+1)∇⊃m[h⍳⊂⍵;1+b⊃⍨⍺|⍨≢b]}
⎕←0t'AAA'⋄⎕←∧/0t¨h/⍨'A'=⊃⍤⌽¨h