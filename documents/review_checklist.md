# Driver review checklist (growing list)

This file records review items that must be checked whenever the IQS9151 driver is touched. Add new items as they arise so they remain visible to future reviewers.

## I2C Update Key / I2C Slave Address safety

- The I2C Update Key (`0x1176`) must **never** be written with the unlock value (`0xA3`). Keep it at `0x00`.
- The driver must not write the I2C Slave Address register (`0x1177`). The device default `0x56` should remain unchanged.
- Block writes must exclude both registers so that accidental key changes cannot unlock address updates. In the current driver, the configuration block starts at `0x1178`, skipping `0x1176–0x1177`.
