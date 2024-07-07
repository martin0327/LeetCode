<h2><a href="https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/">3212. Count Submatrices With Equal Frequency of X and Y</a></h2><h3>Medium</h3><hr><div><p>Given a 2D character matrix <code>grid</code>, where <code>grid[i][j]</code> is either <code>'X'</code>, <code>'Y'</code>, or <code>'.'</code>, return the number of <span data-keyword="submatrix">submatrices</span> that contains:</p>

<ul>
	<li><code>grid[0][0]</code></li>
	<li>an <strong>equal</strong> frequency of <code>'X'</code> and <code>'Y'</code>.</li>
	<li><strong>at least</strong> one <code>'X'</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [["X","Y","."],["Y",".","."]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/06/07/examplems.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 175px; height: 350px;"></strong></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [["X","X"],["X","Y"]]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>No submatrix has an equal frequency of <code>'X'</code> and <code>'Y'</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[".","."],[".","."]]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>No submatrix has at least one <code>'X'</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 1000</code></li>
	<li><code>grid[i][j]</code> is either <code>'X'</code>, <code>'Y'</code>, or <code>'.'</code>.</li>
</ul>
</div>