#!/bin/dyalogscript
l←⊃⎕NGET'./input.txt'1
s←{⊃(//⎕vfi)⍵/⍨⍵∊' ',⎕d}¨1↓':'(≠⊆⊢)∊l,¨' '
v←⊃s⋄m←{⍵⊂⍨1 0 0⍴⍨≢⍵}¨1↓s
tr←{
    d s l←⍺⋄o←⍵∘.-s
    r←⍳∘1⍤1⊢(o≥0)∧l≥[2]o⋄i←r≠1+≢l
    (1 1⍉(i⌿o+[2]d)[;i/r])@(⍸i)⊢⍵
}
⎕←⌊/⊃tr/({↓⍉↑⍵}¨⌽m),⊂v
⍝ 05-12: Giving up due to RIDE bugs, may
⍝        revisit this implementation later.