<h2><a href="https://leetcode.com/problems/count-valid-suffix-sorts-i">4107. Count Valid Suffix Sorts I</a></h2><h3>Medium</h3><hr><p>You are given two integer arrays <code>nums</code> and <code>target</code>, both of length <code>n</code>.</p>

<p>For each index <code>i</code>, consider sorting the <strong>suffix</strong> <code>nums[i..n - 1]</code> of the original array in <strong>non-increasing order</strong>.</p>

<p>Return the number of indices <code>i</code> for which the resulting array is equal to <code>target</code>.</p>

<p>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>A <strong>suffix</strong> of an array is a subarray that begins at any index and extends to the end of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], target = [3,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><code>i = 0</code>: The resulting array is <code>[3, 2, 1]</code>, which equals <code>target</code>.</li>
	<li><code>i = 1</code>: The resulting array is <code>[1, 3, 2]</code>.</li>
	<li><code>i = 2</code>: The resulting array is <code>[1, 2, 3]</code>.</li>
</ul>

<p>Only <code>i = 0</code> is valid, so the answer is 1.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,5,6,4,6], target = [1,5,6,6,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>Choosing either <code>i = 2</code> or <code>i = 3</code> results in <code>[1, 5, 6, 6, 4]</code>. No other index produces <code>target</code>. Therefore, the answer is 2.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [7,6,8], target = [8,6,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>Sorting the suffix starting at indices 0, 1, and 2 produces <code>[8, 7, 6]</code>, <code>[7, 8, 6]</code>, and <code>[7, 6, 8]</code>, respectively. None equals <code>target</code>, so the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length == target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], target[i] &lt;= 10<sup>​​​​​​​5</sup></code>​​​​​​​​​​​​​​</li>
</ul>
