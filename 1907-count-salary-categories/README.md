<h2><a href="https://leetcode.com/problems/count-salary-categories/">1907. Count Salary Categories</a></h2><h3>Medium</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Table: <code>Accounts</code></p>

<pre>+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
account_id is the primary key for this table.
Each row contains information about the monthly income for one bank account.
</pre>

<p>&nbsp;</p>

<p>Write an SQL query to report the number of bank accounts of each salary category. The salary categories are:</p>

<ul>
	<li><code>"Low Salary"</code>: All the salaries <strong>strictly less</strong> than <code>$20000</code>.</li>
	<li><code>"Average Salary"</code>: All the salaries in the <strong>inclusive</strong> range <code>[$20000, $50000]</code>.</li>
	<li><code>"High Salary"</code>: All the salaries <strong>strictly greater</strong> than <code>$50000</code>.</li>
</ul>

<p>The result table <strong>must</strong> contain all three categories. If there are no accounts in a category, then report <code>0</code>.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The query result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
<strong>Output:</strong> 
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
<strong>Explanation:</strong> 
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.
</pre>
</div>