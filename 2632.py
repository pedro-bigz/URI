attacks = {
    'fire': {
        'dano': 200,
        'lvls': [20, 30, 50]
    },
    'water': {
        'dano': 300,
        'lvls': [10, 25, 40]
    },
    'earth': {
        'dano': 400,
        'lvls': [25, 55, 70]
    },
    'air': {
        'dano': 100,
        'lvls': [18, 38, 60]
    }
}

n = int(input())

for _ in range(n):
    w, h, qx0, qy0 = map(int, input().split())
    attack_name, lvl, cx0, cy0 = input().split()
    
    cx0, cy0 = [ int(cx0), int(cy0) ]
    raio = attacks[attack_name]['lvls'][int(lvl) - 1]
    