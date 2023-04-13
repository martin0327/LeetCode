SELECT
  st.student_id,
  st.student_name,
  sb.subject_name,
  COUNT(e.subject_name) AS attended_exams
FROM
  students st
  JOIN subjects sb
  LEFT JOIN examinations e ON st.student_id=e.student_id
  AND sb.subject_name=e.subject_name
GROUP BY
  student_id,
  subject_name
ORDER BY
  student_id,
  subject_name