#!/bin/dyalogscript
l←⊃⎕NGET'./input.txt'1
z←{≢10(↑∩↓)⊃(//⎕vfi⍵)}¨l
⎕←+/⌊2*¯1+z⋄⎕←+/∊⌹(=-<×-⍨<1+z⌷⍨⊣)/¨⍳2⍴≢z