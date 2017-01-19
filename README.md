# Firebox

A litte fire command center for my son.

## States & Transitions

```
POWER_OFF:
  -> IDLE

IDLE: Home green (remains on)
  start -> ALARM

ALARM: Strip blue/white
  3 sec elapsed -> BURNING

BURNING: Strip pulsates red (less bright on the sides), random location LED truns on
  switches in right configuration -> EXTINGUISHED

EXTINGUISHED: Strip fades to green, then fades to off
  fade done -> IDLE
```

Later: Do something with the key pad (see keypad library).

## Circuit

![](images/circuit.jpg)

## Development notes

We are not using object oriented concepts here, because the the students haven't seen this yet.