#!/bin/dyalogscript
l←⊃⎕NGET'./input.txt' 1
⍝ Part 1:
⎕←⊃+/{⊃⊃//⎕vfi(⊃,⊃∘⌽)⍵/⍨⎕d∊⍨⍵}¨l
⍝ Part 2:
n←2 9⍴'one' 'two' 'three' 'four' 'five' 'six' 'seven' 'eight' 'nine',1↓⎕d
⎕←⊃+/{10⊥(⊃,⊃∘⌽)0~⍨+⌿(⍳9)+.×2 1 3⍉↑n⍷¨⊂⍵}¨l