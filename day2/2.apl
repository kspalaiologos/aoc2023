#!/bin/dyalogscript
l←⊃⎕NGET'./input.txt'1
⎕←⌽+⌿↑{
  n←(⊃⍤//⍤⎕VFI)¨⍵⊆⍨⍵∊⎕D
  c←0~⍨⊃1 2 3+.×'red' 'green' 'blue'⍷¨⊂⍵
  m←⌈/{n[¯2+1↓⍵]}⌸1 2 3,c
  (×/m),(⊃n)×m∧.≤12 13 14
}¨l