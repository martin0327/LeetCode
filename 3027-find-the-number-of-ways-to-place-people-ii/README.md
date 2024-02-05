<h2><a href="https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/">3027. Find the Number of Ways to Place People II</a></h2><h3>Hard</h3><hr><div><p>You are given a 2D array <code>points</code> of size <code>n x 2</code> representing integer coordinates of some points on a 2D-plane, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>We define the <strong>right</strong> direction as positive x-axis (<strong>increasing x-coordinate</strong>) and the <strong>left</strong> direction as negative x-axis (<strong>decreasing x-coordinate</strong>). Similarly, we define the <strong>up</strong> direction as positive y-axis (<strong>increasing y-coordinate</strong>) and the <strong>down</strong> direction as negative y-axis (<strong>decreasing y-coordinate</strong>)</p>

<p>You have to place <code>n</code> people, including Chisato and Takina, at these points such that there is <strong>exactly one</strong> person at every point. Chisato wants to be alone with Takina, so Chisato will build a rectangular fence with Chisato's position as the <strong>upper left corner</strong> and Takina's position as the <strong>lower right corner</strong> of the fence (<strong>Note</strong> that the fence <strong>might not</strong> enclose any area, i.e. it can be a line). If any person other than Chisato and Takina is either <strong>inside</strong> the fence or <strong>on</strong> the fence, Chisato will be sad.</p>

<p>Return <em>the number of <strong>pairs of points</strong> where you can place Chisato and Takina, such that Chisato <strong>does not</strong> become sad on building the fence</em>.</p>

<p><strong>Note</strong> that Chisato can only build a fence with Chisato's position as the upper left corner, and Takina's position as the lower right corner. For example, Chisato cannot build either of the fences in the picture below with four corners <code>(1, 1)</code>, <code>(1, 3)</code>, <code>(3, 1)</code>, and <code>(3, 3)</code>, because:</p>

<ul>
	<li>With Chisato at <code>(3, 3)</code> and Takina at <code>(1, 1)</code>, Chisato's position is not the upper left corner and Takina's position is not the lower right corner of the fence.</li>
	<li>With Chisato at <code>(1, 3)</code> and Takina at <code>(1, 1)</code>, Takina's position is not the lower right corner of the fence.</li>
</ul>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/04/example0alicebob-1.png" style="width: 750px; height: 308px;padding: 10px; background: #fff; border-radius: .5rem;">
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/04/example1alicebob.png" style="width: 376px; height: 308px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;">
<pre><strong>Input:</strong> points = [[1,1],[2,2],[3,3]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no way to place Chisato and Takina such that Chisato can build a fence with Chisato's position as the upper left corner and Takina's position as the lower right corner. Hence we return 0. 
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/04/example2chisatotakina.png" style="width: 1121px; height: 308px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;">
<pre><strong>Input:</strong> points = [[6,2],[4,4],[2,6]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to place Chisato and Takina such that Chisato will not be sad:
- Place Chisato at (4, 4) and Takina at (6, 2).
- Place Chisato at (2, 6) and Takina at (4, 4).
You cannot place Chisato at (2, 6) and Takina at (6, 2) because the person at (4, 4) will be inside the fence.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/04/chisatotakinaexample3.png" style="width: 1123px; height: 308px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;">
<pre><strong>Input:</strong> points = [[3,1],[1,3],[1,1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to place Chisato and Takina such that Chisato will not be sad:
- Place Chisato at (1, 1) and Takina at (3, 1).
- Place Chisato at (1, 3) and Takina at (1, 1).
You cannot place Chisato at (1, 3) and Takina at (3, 1) because the person at (1, 1) will be on the fence.
Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>9</sup> &lt;= points[i][0], points[i][1] &lt;= 10<sup>9</sup></code></li>
	<li>All <code>points[i]</code> are distinct.</li>
</ul>
</div>