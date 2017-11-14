from sys import argv
from random import choice, randint

nb_configs = int(argv[1])
nb_ips = int(argv[2])
nb_apps = int(argv[3])

ip_list = []
for i in range(0, nb_ips):
  while True:
    ip = "192.168.0.{}".format(randint(0,256))
    if ip not in ip_list:
      ip_list.append(ip)
      break
#print(ip_list)

port_list = []
for i in range(0, nb_apps):
  while True:
    port = randint(0,65536)
    if port not in port_list:
      port_list.append(port)
      break
#print(port_list)

app_list = []
for i in range(0, nb_apps):
  while True:
    app = randint(0,32768)
    if app not in app_list:
      app_list.append((app,port_list[-1]))
      port_list = port_list[:-1]
      break
#print(app_list)

cfg_list = []
for i in range(0, nb_configs):
  while True:
    cfg = (choice(ip_list), choice(app_list))
    if cfg not in cfg_list:
      cfg_list.append(cfg)
      break
print("\n".join(["{},{},{}".format(x[1][0], x[1][1], x[0]) for x in cfg_list]))
