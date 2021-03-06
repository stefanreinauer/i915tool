extern int verbose;
int i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	fprintf(stderr, "%s\n", __func__);
	int try, ret;

		for (ret = 0; ret < num; ret++) {
			if (verbose > 1) fprintf(stderr, "master_xfer[%d] %c, addr=0x%02x, "
				"len=%d%s\n", ret, (msgs[ret].flags & I2C_M_RD)
				? 'R' : 'W', msgs[ret].addr, msgs[ret].len,
				(msgs[ret].flags & I2C_M_RECV_LEN) ? "+" : "");
		}

		for (ret = 0, try = 0; try <= adap->retries; try++) {
			ret = adap->algo->master_xfer(adap, msgs, num);
			if (ret != -EAGAIN)
				break;
		}
		if (verbose > 1) fprintf(stderr, 
			"i2c transfer returns %d\n", ret);
		return ret;
}
