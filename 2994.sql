SELECT doctors.name, round(sum((work_shifts.bonus/100)*(attendances.hours * 150) + (attendances.hours * 150)), 1) as salary
FROM doctors
INNER JOIN attendances ON doctors.id = attendances.id_doctor
INNER JOIN work_shifts ON work_shifts.id = attendances.id_work_shift
GROUP BY doctors.id
ORDER BY salary DESC
