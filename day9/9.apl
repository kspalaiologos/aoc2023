#!/bin/dyalogscript
⍝ Stupid VFI...
l←⊃⍤(//⎕vfi)∘('-'⎕R'¯')¨⊃⎕NGET'input.txt'1
⍝ Alternatively, for fun (⎕io←0): ⌈+/{(≢⍵)⊥⌽(⌹∘.*⍨⍳≢⍵)+.×⍵}¨l
f←-/⌽×≢!⍨⍳∘≢⋄⎕←+/f¨l⋄⎕←+/f¨⌽¨l