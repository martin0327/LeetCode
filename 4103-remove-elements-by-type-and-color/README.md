<h2><a href="https://leetcode.com/problems/remove-elements-by-type-and-color">4103. Remove Elements by Type and Color</a></h2><h3>Medium</h3><hr><p>You are given three integer arrays <code>types</code>, <code>colors</code>, and <code>groupSize</code>, where <code>types</code> and <code>colors</code> have length <code>n</code>, and <code>groupSize</code> has length <code>m</code>.</p>

<ul>
	<li><code>types[i]</code> represents the type of the element at index <code>i</code>.</li>
	<li><code>colors[i]</code> represents the color of the element at index <code>i</code>.</li>
	<li><code>groupSize[t]</code> represents the required number of elements in a removable group of type <code>t</code>.</li>
</ul>

<p>In one operation, you may remove <strong>exactly</strong> <code>groupSize[t]</code> <strong>consecutive</strong> elements if all of them have type <code>t</code> and the <strong>same color</strong>.</p>

<p>After each removal, the remaining elements become <strong>adjacent</strong> again while maintaining their relative order.</p>

<p>Return <code>true</code> if it is possible to remove all elements using a sequence of valid operations. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">types = [0,1,1,0], colors = [5,3,3,5] , groupSize = [2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>First, remove the consecutive elements at indices 1 and 2. Both elements have type 1, color 3, and the group size is equal to <code>groupSize[1] = 2</code>.</li>
	<li>The remaining sequence is: <code>types = [0, 0]</code>, <code>colors = [5, 5]</code></li>
	<li>Now remove the two remaining elements. They have type 0, color 5, and the group size is equal to <code>groupSize[0] = 2</code>.</li>
	<li>All elements have been removed, so the answer is <code>true</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">types = [0,1,0], colors = [9,9,9], groupSize = [3,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>No valid operation can be performed because no consecutive group satisfies its required size.</li>
	<li>Therefore, it is impossible to remove all elements, so the answer is <code>false</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">types = [2,0,1,2], colors = [7,5,4,7], groupSize = [3,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>Remove the element at index 2. It has type 1, color 4, and forms a consecutive group of size <code>groupSize[1] = 1</code>.</li>
	<li>The remaining sequence is: <code>types = [2, 0, 2]</code>, <code>colors = [7, 5, 7]</code>.</li>
	<li>No further operations can be performed, so the answer is <code>false</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == types.length == colors.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m == groupSize.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= types[i] &lt;= m - 1</code></li>
	<li><code>1 &lt;= colors[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= groupSize[t] &lt;= n</code></li>
</ul>
