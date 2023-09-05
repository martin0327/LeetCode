<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-a-special-number/">2844. Minimum Operations to Make a Special Number</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> string <code>num</code> representing a non-negative integer.</p>

<p>In one operation, you can pick any digit of <code>num</code> and delete it. Note that if you delete all the digits of <code>num</code>, <code>num</code> becomes <code>0</code>.</p>

<p>Return <em>the <strong>minimum number of operations</strong> required to make</em> <code>num</code> <i>special</i>.</p>

<p>An integer <code>x</code> is considered <strong>special</strong> if it is divisible by <code>25</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> num = "2245047"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Delete digits num[5] and num[6]. The resulting number is "22450" which is special since it is divisible by 25.
It can be shown that 2 is the minimum number of operations required to get a special number.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> num = "2908305"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Delete digits num[3], num[4], and num[6]. The resulting number is "2900" which is special since it is divisible by 25.
It can be shown that 3 is the minimum number of operations required to get a special number.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> num = "10"
<strong>Output:</strong> 1
<strong>Explanation:</strong> Delete digit num[0]. The resulting number is "0" which is special since it is divisible by 25.
It can be shown that 1 is the minimum number of operations required to get a special number.

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 100</code></li>
	<li><code>num</code> only consists of digits <code>'0'</code> through <code>'9'</code>.</li>
	<li><code>num</code> does not contain any leading zeros.</li>
</ul>
</div>