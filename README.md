<p align="center">
  <a href="https://github.com/1nfocalypse/AMBiDEX">
	<img alt="AMBiDEX" src="https://i.imgur.com/Dn97W9B.png"/>
  </a>
</p>
<p align="center">
  <a href="https://choosealicense.com/licenses/MIT/">
  	<img alt="License: GPL-3.0" src="https://img.shields.io/github/license/1nfocalypse/AMBiDEX"/>
  </a>
</p>
<h2 align="center">AMBiDEX</h3>
<h3 align="center">
  A Toy Dining Cryptographers Implementation
</h2>
<p align="center">
  By <a href="https://github.com/1nfocalypse">1nfocalypse</a>
</p>

# What is it?
AMBiDEX is a toy illustration of [Chaum's Dining Cryptographers Problem](https://en.wikipedia.org/wiki/Dining_cryptographers_problem), a secure multiparty computation problem focused on unconditional sender and recipient untraceability.
This means that so long as two parties are involved in some means of communication over what is known as a DC-net (Dining Cryptographers Network), an observer would be unable to determine which party is communicating at any given time. 
With the addition of asymmetric encryption, one is thus also able to make it such that an observer is unable to determine what is being sent within the DC-net. As a result, this method provides an incredibly potent means for anonymous
communication in group settings.

# Usage
To use the program, simply configure it to your liking (default is 3 diners, with one of them paying) in the configuration menu. Then run the simulation as much as you please. The current configuration may also be checked from the menu.

# The Problem
Per Bruce Schneier's *Applied Cryptography: Protocols, Algorithms, and Source Code in C*, the problem is as follows:

Three cryptographers are sitting down to dinner at their favorite three-star restaurant. Their waiter informs them that arrangements have been made with the
maitre d'hotel for the bill to be paid anonymously. One of the cryptographers might be paying for the dinner, or it might have been the NSA. The three 
cryptographers respect each other's right to make an anonymous payment, but they wonder if the NSA is paying.

# The Solution
The solution is to organize the cryptographers in a circle. Then, allow each cryptographer to flip a fair coin, yielding a binary value. The result of this flip is shared with the cryptographer to the right. The cryptographer to the right
will have also flipped a coin. If the values are the same, they will declare as such, and if they differ, they will also declare this. However, if the cryptographer to the right paid, they will declare the inverse of whatever is true, such
that if both coins are the same, they will declare they are different, and vice versa. As the cryptographers proceed throughout, they will sum the number of "different" results. If the number is odd, then one of the cryptographers paid.
Otherwise, the NSA paid.

# Mathematically Speaking? (Example)
The operation of the DC-net can best be explained via the exclusive or, or XOR, function. Let a result of Heads be 1, and a result of tails be 0. Alice, Bob, and Charlie each obtain a random bit. Let A = 1, B = 0, C = 0. From here, we set up the equations

$$A \oplus B \rightarrow 1 \oplus 0 = 1$$

$$B \oplus C \rightarrow 0 \oplus 0 = 0$$

$$C \oplus A \rightarrow 0 \oplus 1 = 1$$


Taking these results, we set up the final equation
```math
$$1 \oplus 0 \oplus 1 \rightarrow 1 \oplus 1 = 0$$
```
Denoting that the NSA paid. However, in the same scenario, if one of the reported combinations was to be a lie, we would encounter a bitflip, yielding a result of 1. For example, if Bob paid, we find

$$A \oplus B \rightarrow \lnot(1 \oplus 0) = 0$$

$$B \oplus C \rightarrow 0 \oplus 0 = 0$$

$$C \oplus A \rightarrow 0 \oplus 1 = 1$$

$$0 \oplus 0 \oplus 1 \rightarrow 0 \oplus 1 = 1$$


As such, we are able to determine if a member of the group sent a message, albeit not which member.

# Asymmetrical Cryptography
If a member of a DC-net wishes to send a message privately to another member of the DC-net, all that must be done is for each member to publish a public key of an agreed upon asymmetric scheme (RSA, ECDLP, NTRU, etc.). In theory, they now have a valid means
of private communication. In practicum, the sender publishes a symmetric key encrypted with the target's public key, which the intended recipient decrypts. Further communications are then conducted via public posting of symmetrically encrypted messages, when
only the two intended members have the symmetric key. They key can then be further shared in the same manner to create private groups, or retained to ensure private communication betwen users.

# Problems with the DC-net
The DC-net relies on a reliable broadcast network, which is a major postulation. In the case of noise or collisions, i.e. multiple members attempting to communicate simultaneously, we cripple the DC-net permanently. Solutions for this are offered in both
the [Dissent Project](https://dedis.cs.yale.edu/dissent/) and Waidner and Pfitzmann's *The Dining Cryptographers in the Disco: Unconditional Sender and Recipient Untraceability with Computationally Secure Serviceability* via built in tolerance and signature
verification, and random shuffles, respectively. Another issue presented is a disruption attack, in which a malicious agent lies about the results of their shared information. A solution to this is offered yet again by Waidner in Pfitzmann in the aforementioned
paper.

# Further Reading and References
- [Chaum, David - The Dining Cryptographers Problem: Unconditional Sender and Recipient Untraceability](https://www.cs.cornell.edu/people/egs/714-spring05/dcnets.html)
- [Chaum's Dining Cryptographers Problem: Wikipedia](https://en.wikipedia.org/wiki/Dining_cryptographers_problem)
- [Schneier, Bruce - Applied Cryptography: Protocols, Algorithms and Source Code in C](https://www.amazon.com/dp/1119096723/?coliid=IXN99D19IDT4Y)
- [Waidner, Michael; Pfitzmann, Birgit - The Dining Cryptographers in the Disco: Unconditional Sender and Recipient Untraceability with Computationally Secure Serviceability](https://www.researchgate.net/publication/243686824_The_Dining_Cryptographers_in_the_Disco_Unconditional_Sender_and_Recipient_Untraceability_with_Computationally_Secure_Serviceability)
- [Dissent](https://dedis.cs.yale.edu/dissent/)
