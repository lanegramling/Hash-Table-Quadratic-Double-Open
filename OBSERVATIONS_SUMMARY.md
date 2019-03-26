
#### Summary of observations - Quadratic Probing vs. Double Hashing

  In general, double hashing tends to perform more reliably than quadratic probing
  for hashing algorithms by mitigating some of the issues inherent with the quadratic
  probing technique's behavioral predisposition towards clustering when compared
  against double hashing. Additionally, the double hashing technique naturally
  encounters a smaller number of repeated collisions upon insertion attempts,
  lending itself the quality of being a generally speedier approach in the average case.
  Because of this, we observe that the double hashing technique is less likely
  than quadratic probing to fail at inserting a value into its table while there's
  still space available in the table. This allows it to be generally more space
  efficient, making better use of its allocated memory than quadratic probing and
  thus having a slower decay in the probability of successful insertion as the
  load factor approaches 1.
