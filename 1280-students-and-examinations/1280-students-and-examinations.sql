WITH
  t AS (
    SELECT
      st.student_id,
      st.student_name,
      sb.subject_name
    FROM
      students st
      JOIN subjects sb
  )
SELECT
  t.student_id,
  t.student_name,
  t.subject_name,
  COUNT(e.subject_name) AS attended_exams
FROM
  t
  LEFT JOIN examinations e ON t.student_id=e.student_id
  AND t.subject_name=e.subject_name
GROUP BY
  student_id,
  subject_name
ORDER BY
  student_id,
  subject_name