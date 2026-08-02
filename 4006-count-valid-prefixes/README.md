<h2><a href="https://leetcode.com/problems/count-valid-prefixes">4006. Count Valid Prefixes</a></h2><h3>Easy</h3><hr><p>You are given a <strong>binary</strong> string <code>s</code>.</p>

<p>A <strong>prefix</strong> of <code>s</code> is considered <strong>valid</strong> if its characters can be rearranged to form an <strong>alternating</strong> string.</p>

<p>Return the number of valid prefixes of <code>s</code>.</p>

<p>A <strong>binary</strong> string is a string consisting only of <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>.</p>

<p>A <strong>prefix</strong> of a string is a <strong>substring</strong> that starts from the beginning of the string and extends to any point within it.</p>

<p>A <strong>substring</strong> is a contiguous <b>non-empty</b> sequence of characters within a string.</p>

<p>A string is considered <strong>alternating</strong> if no two adjacent characters are equal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;00101&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The valid prefixes are:</p>

<ul>
	<li><code>&quot;0&quot;</code>: It is already an alternating string.</li>
	<li><code>&quot;001&quot;</code>: It can be rearranged into <code>&quot;010&quot;</code>, which is an alternating string.</li>
	<li><code>&quot;00101&quot;</code>: It can be rearranged into <code>&quot;01010&quot;</code>, which is an alternating string.</li>
</ul>

<p>Thus, the answer is 3.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;101&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>All prefixes of <code>s = &quot;101&quot;</code> are already alternating strings. Thus, the answer is 3.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists only of <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>.</li>
</ul>
