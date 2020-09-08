# Time:  O(n), n is the number of cells
# Space: O(n)

class Solution(object):
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def goBack(robot):
            robot.turnLeft()
            robot.turnLeft()
            robot.move()
            robot.turnRight()
            robot.turnRight()

        def dfs(pos, robot, d, lookup):
            robot.clean()
            for _ in directions:
                new_pos = (pos[0]+directions[d][0],
                           pos[1]+directions[d][1])
                if new_pos not in lookup:
                    lookup.add(new_pos)
                    if robot.move():
                        dfs(new_pos, robot, d, lookup)
                        goBack(robot)
                robot.turnRight()
                d = (d+1) % len(directions)
        
        dfs((0, 0), robot, 0, set())
